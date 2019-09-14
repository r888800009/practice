#include <stdio.h>
#include <windows.h>

// x86
// disable SafeSEH
// cl seh.c /DYNAMICBASE:NO /link /FIXED /SAFESEH:NO

void shellcode() { system("cmd"); }

void call() { shellcode(); }

DWORD crash() {
  puts("oh crash");
  fflush(stdout);
  exit(0);
}

int main() {
  size_t array[1];
  int index;
  int tmp;

  printf("hint: %p\n", shellcode);
  printf("hint2: %p\n", call);
  printf("Give me index\n");
  fflush(stdout);
  scanf("%d", &index);

  printf("Give me new SEH handler decimal address\n");
  fflush(stdout);
  scanf("%d", array + index);

  __try {
    int zero = 0;
    int a = 1 / zero;
    printf("Hello, World!\n");
    fflush(stdout);
  } __except (crash()) {
  }

  printf("Will not execute\n");
  fflush(stdout);

  return 0;
}
