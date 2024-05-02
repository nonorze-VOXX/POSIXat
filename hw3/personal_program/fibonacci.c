
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int index;
} PageStruct;

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void *fib(void *param) {
  PageStruct *params = (PageStruct *)param;
  int index = 0;
  int pre = 0;
  struct node *now = head;
  while (1) {
    if (now->next == NULL) {
      continue;
    }
    pre = now->data;
    now = now->next;
    index++;
    if (index == params->index - 1) {
      struct node *next = (struct node *)malloc(sizeof(struct node));
      next->data = pre + now->data;
      now->next = next;
      break;
    }
  }
  free(param);
  return 0;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "usage: ./fib <integer value>\n");
    return -1;
  }
  head = (struct node *)malloc(sizeof(struct node));
  head->data = 0;
  struct node *second = (struct node *)malloc(sizeof(struct node));
  head->next = second;
  second->data = 1;

  pthread_t last_tid;

  int n = atoi(argv[1]);
  printf("n: %d\n", n);
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  for (int i = 2; i < n; i++) {
    pthread_t tid;
    PageStruct *p = (PageStruct *)malloc(sizeof(PageStruct));
    p->index = i;
    pthread_create(&tid, &attr, fib, p);
    last_tid = tid;
  }
  pthread_join(last_tid, NULL);
  for (struct node *now = head; now != NULL;) {
    printf("%d ", now->data);
    struct node *prev = now;
    now = now->next;
    free(prev);
  }
  printf("\n");

  return 0;
}