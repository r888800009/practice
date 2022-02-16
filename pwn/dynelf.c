#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  puts("Hello World!");
  printf("main(): %p\n", main);

  while (1) {
    printf("> ");
    int select = -1;
    scanf("%d", &select);
    switch (select) {
      case 1:
        printf("set addr: ");
        size_t *addr;
        scanf("%p", &addr);
        printf("!");
        write(1, addr, 4);
        printf("!");
        break;
      case 2:
        goto bye;
        break;
      default:
        break;
    }
  }

bye:
  puts("set func ptr:");
  void (*func)();
  scanf("%p", &func);
  func("/bin/sh");

  return 0;
}
