
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int page_number;
  int offset;
} PageStruct;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "input error");
    return -1;
  }
  int n = atoi(argv[1]);
  printf("n: %d\n", n);
  PageStruct *params = (PageStruct *)malloc(sizeof(PageStruct));
  params->page_number = n / 4096;
  params->offset = n % 4096;
  printf("page number: %d\n", params->page_number);
  printf("offset: %d\n", params->offset);
}