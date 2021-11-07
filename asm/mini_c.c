/*
gcc -c mini_c.c -nodefaultlibs -no-pie -fno-stack-protector -z execstack
ld -T mini_c.ld -s -o ./mini_c mini_c.o

wc mini_c
./mini_c
*/

int _start() {
  __asm__(
      "	movq	%rsp, %rbp;"
      "	movabsq	$8031924123371070824, %rax;"
      "	movq	%rax, -13(%rbp);"
      "	movl	$0x21646c72, -5(%rbp);"
      "	movb	$0x0a, -1(%rbp);"
      "mov $1, %rax;"
      "mov %rax, %rdi;"
      "mov %rbp, %rsi;"
      "sub $0xd, %rsi;"
      "mov $13, %rdx;"
      "syscall;"
      "	mov $231, %rax;"
      "xor %rdi, %rdi;"
      "syscall;");
}

