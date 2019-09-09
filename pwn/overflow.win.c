#include <stdio.h>
#include <windows.h>

#define SHELLCODE_MAX 512

void *shellcode;

int main() {
  char buf[10];

  shellcode =
      VirtualAlloc(0, SHELLCODE_MAX, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

  printf("hint:%p\n", shellcode);
  puts("give me shell code");
  fflush(stdout);
  fread(shellcode, 1, SHELLCODE_MAX, stdin);

  puts("Overflow me");
  fflush(stdout);
  fread(buf, 0x30, 1, stdin);

  return 0;
}
