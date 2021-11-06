#include <stdio.h>

/*
gcc -g -fno-stack-protector -z execstack -no-pie symexec_rip.c -o symexec_rip
docker run --rm -it -v $(pwd):/work ctf_ubuntu1804 bash 
*/

void shellcode()
{
  // fix stack alignment 0x10 syscall
  __asm__("pop %rax"); // fix stack
  system("/bin/sh");
}

int main()
{
  char bof[10];
  puts("Overflow me");
  fflush(stdout);
  gets(bof);

  return 0;
}