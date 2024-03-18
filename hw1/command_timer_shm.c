
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <sys/time.h>
#include <unistd.h>

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int exit_status;
  int shmid = shmget(IPC_PRIVATE, sizeof(struct timeval), IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }
  int *shmatshm = shmat(shmid, NULL, 0);
  struct timeval *shared_variable = (struct timeval *)shmatshm;
  if (*shmatshm == -1) {
    perror("shmat");
    exit(1);
  }
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  } else if (pid == 0) {
    // get time of day
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Time of day: %ld\n", tv.tv_usec);

    *shared_variable = tv;
    // run cal
    execvp(argv[1], argv + 1);
    // return

  } else {
    wait(&exit_status);
    printf("Child process exited with status %d\n", WEXITSTATUS(exit_status));
    printf("Shared variable: %ld\n", shared_variable->tv_usec);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("return: %ld\n", tv.tv_usec - shared_variable->tv_usec);
    // if(WIFEXITED(exit_status) && WEXITSTATUS(exit_status) == 0
  }
  return 0;
}
