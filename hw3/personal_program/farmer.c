#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t using;
int north_count = 0;
int south_count = 0;

void *north_farmer(void *arg) {
  while (1) {
    sem_wait(&using);
    if (south_count != 0) {
      sem_post(&using);
    } else {
      break;
    }
  }
  north_count++;
  sem_post(&using);
  // passing
  printf("North farmer is passing\n");
  sem_wait(&using);
  north_count--;
  sem_post(&using);
}
void *south_farmer(void *arg) {
  while (1) {
    sem_wait(&using);
    if (north_count != 0) {
      sem_post(&using);
    } else {
      break;
    }
  }
  south_count++;
  sem_post(&using);
  // passing
  printf("South farmer is passing\n");

  // sleep for a random period of time
  int sleep_time = rand() % 5;
  sleep(sleep_time);

  sem_wait(&using);
  south_count--;
  sem_post(&using);
}

int main() {
  sem_init(&using, 0, 1);
  pthread_t north_farmer_thread, south_farmer_thread;
  for (int i = 0; i < 100; i++) {
    pthread_create(&north_farmer_thread, NULL, north_farmer, NULL);
    pthread_create(&south_farmer_thread, NULL, south_farmer, NULL);
  }
  pthread_join(north_farmer_thread, NULL);
  pthread_join(south_farmer_thread, NULL);
  sem_destroy(&using);
  return 0;
}
