#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

// gcc simple-signal.c -o simple-signal -g
void handler(int sig) { printf("Caught signal %d\n", sig); }

int main() {
  signal(SIGUSR2, handler);
  while (1) {
    printf("Hello, world!\n");
    sleep(1);
  }
  return 0;
}

