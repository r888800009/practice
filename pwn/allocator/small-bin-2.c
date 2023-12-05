#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *ptr1[20];
  int *ptr2[20];

  for (size_t i = 0; i < 13; i++) {
    int *split;
    ptr1[i] = malloc(0x100);
    split = malloc(0x10);
    ptr2[i] = malloc(0x110);
    split = malloc(0x10);
  }

  for (size_t i = 0; i < 13; i++) {
    free(ptr1[i]);
    raise(SIGINT);
    free(ptr2[i]);
    raise(SIGINT);
  }

  malloc(0x10);

  raise(SIGINT);

  return 0;
}

// gcc -o small-bin-2 small-bin-2.c -no-pie -g