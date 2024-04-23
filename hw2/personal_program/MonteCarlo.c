#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 4

int total_points = 0;
int points_in_circle = 0;

void *monte_carlo(void *param) {
  int points = total_points / NUM_THREADS;
  int points_in_circle_thread = 0;
  for (int i = 0; i < points; i++) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;
    if (x * x + y * y <= 1) {
      points_in_circle_thread++;
    }
  }
  points_in_circle += points_in_circle_thread;
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  total_points = 1e8; // 100000000
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  srand(time(NULL));
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], &attr, monte_carlo, NULL);
  }
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("pi: %f\n", 4 * (double)points_in_circle / total_points);
  return 0;
}