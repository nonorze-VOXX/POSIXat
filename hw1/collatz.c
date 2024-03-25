
// create child process to calculate collatz sequence
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void collatz(int n) {
  printf("%d", n);
  while (n != 1 && n > 0) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    printf(", %d", n);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number>\n", argv[0]);
    return 1;
  }
  int fd[2];
  if (pipe(fd) == -1) {
    perror("pipe");
    exit(1);
  }

  int n = atoi(argv[1]);
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid != 0) {
    close(fd[0]);
    int result = write(fd[1], &n, sizeof(n));
    if (result != sizeof(n)) {
      perror("write");
      exit(1);
    }
    close(fd[1]);
  } else {
    close(fd[1]);
    int n;
    int result = read(fd[0], &n, sizeof(n));
    if (result != sizeof(n)) {
      perror("read");
      exit(1);
    }
    collatz(n);
    close(fd[0]);
  }
  return 0;
}
