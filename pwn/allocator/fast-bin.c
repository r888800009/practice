#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *ptr1[20];
  int *ptr2[20];

  for (size_t i = 0; i < 15; i++) {
    int *split;
    ptr1[i] = malloc(0x50);
    ptr2[i] = malloc(0x50);
  }

  for (size_t i = 0; i < 15; i++) {
    free(ptr2[i]);
    raise(SIGINT);
    free(ptr1[i]);
    raise(SIGINT);
  }

  raise(SIGINT);

  return 0;
}