
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <source> <destination>\n", argv[0]);
    exit(1);
  }
  int fd = open(argv[1], O_RDONLY);
  int write_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd < 0) {
    perror("open");
    exit(1);
  }
  char buf[1024];
  int n;
  while ((n = read(fd, buf, sizeof(buf))) > 0) {
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
  close(fd);
  close(write_fd);
}