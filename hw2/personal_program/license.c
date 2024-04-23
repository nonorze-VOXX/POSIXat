// clang-format off
#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <stdio.h>
// clang-format on
#define MAX_RESOURCES 5
int available_resources = MAX_RESOURCES;
int increase_count(int count) {
  available_resources += count;
  return 0;
}
// use mutex to fix avaliable_resources
pthread_mutex_t mutex;
int decrease_count(int count) {
  pthread_mutex_lock(&mutex);
  if (available_resources < count) {
    pthread_mutex_unlock(&mutex);
    return -1;
  } else {
    available_resources -= count;
    pthread_mutex_unlock(&mutex);
    return 0;
  }
}

void *process(void *param) {
  int count = *((int *)param);
  if (decrease_count(count) == 0) {
    printf("Got %d resources, %d remaining\n", count, available_resources);
    increase_count(count);
  } else {
    printf("Failed to get %d resources, %d remaining\n", count,
           available_resources);
  }
  return 0;
}

int main() {
  pthread_t tid1, tid2;
  pthread_mutex_init(&mutex, NULL);
  int count1 = 5;
  int count2 = 5;
  pthread_create(&tid1, NULL, process, &count1);
  pthread_create(&tid2, NULL, process, &count2);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&mutex);
  return 0;
}