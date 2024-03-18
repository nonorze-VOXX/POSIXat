
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
// a function read input file and write to pipe
// child get input from pipe and write to output file
void copy_file(char *input_file, char *output_file) {
  int fd[2];
  if (pipe(fd) == -1) {
    perror("pipe");
    exit(1);
  }
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid != 0) {
    // get time of day
    close(fd[0]);
    int read_fd = open(input_file, O_RDONLY);
    if (read_fd < 0) {
      perror("open");
      exit(1);
    }
    char buf[1024];
    int n;
    while ((n = read(read_fd, buf, sizeof(buf))) > 0) {
      int result = write(fd[1], buf, n);
      printf("result: %d\n", result);
      if (result != n) {
        perror("write");
        exit(1);
      }
    }
    if (n < 0) {
      perror("read");
      exit(1);
    }
    close(read_fd);
    close(fd[1]);
  } else {
    int exit_status;
    close(fd[1]);
    int write_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (write_fd < 0) {
      perror("open");
      exit(1);
    }
    char buf[1024];
    int n;
    while ((n = read(fd[0], buf, sizeof(buf))) > 0) {
      int result = write(write_fd, buf, n);
      if (result != n) {
        perror("write");
        exit(1);
      }
    }
    if (n < 0) {
      perror("read");
      exit(1);
    }
    close(fd[0]);
    close(write_fd);
    wait(&exit_status);
  }
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    exit(1);
  }
  copy_file(argv[1], argv[2]);
}