#include <stdio.h>

char shellcode[256];

int main() {
  char bof[10];
  puts("give me shell code");
  gets(shellcode);

  puts("Overflow me");
  gets(bof);

  return 0;
}
