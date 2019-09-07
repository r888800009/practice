#include <stdio.h>

char shellcode[256];

int main() {
  char bof[10];
  puts("give me shell code");
  fflush(stdout);
  gets(shellcode);

  puts("Overflow me");
  fflush(stdout);
  gets(bof);

  return 0;
}
