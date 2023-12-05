#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *a[40];
  char *b[40];
  char *c[40];

  for (int i = 0; i < 15; i++)
    a[i] = malloc(0x440);
  for (int i = 0; i < 15; i++)
    b[i] = malloc(0x460);
  for (int i = 0; i < 15; i++)
    c[i] = malloc(0x500);

  // i += 2 prevents consolidation
  for (int i = 0; i < 15; i += 2) {
    free(a[i]);
    free(b[i]);
    free(c[i]);
  }

  // make sure chunk put in large bin
  malloc(0x10);

  return 0;
}

// gcc ./large-bin.c -o ./large-bin -g