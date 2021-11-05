#include <stdio.h>

/*
gcc -g -fno-stack-protector -z execstack -no-pie symexec_rip_level2.c -o symexec_rip_level2
docker run --rm -it -v $(pwd):/work ctf_ubuntu1804 bash 

python3 symexec_rip_level2.py
*/

void shellcode()
{
  // fix stack alignment 0x10 syscall
  __asm__("pop %rax"); // fix stack
  system("/bin/sh");
}

void shuffle(char *str)
{
  for (int i = 0; i < 30; i++)
  {
    str[i] = str[(i + 10) % 30] + 10;
  }
}

int main()
{
  char bof[10];
  puts("Overflow me");
  fflush(stdout);
  gets(bof);

  if (strcmp(bof, "test") != 0)
    exit(0);

  shuffle(bof);

  return 0;
}