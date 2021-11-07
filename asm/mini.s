
/*
GCC: Empty program == 23202 bytes?
https://stackoverflow.com/questions/1315926/gcc-empty-program-23202-bytes

as mini.s -o mini.o
ld -T mini.ld -s -o ./mini mini.o

wc mini
./mini
*/

	.text
	.globl	_start
_start:
	movq	%rsp, %rbp
	movabsq	$8031924123371070824, %rax
	movq	%rax, -13(%rbp)
	movl	$0x21646c72, -5(%rbp)
	movb	$0x0a, -1(%rbp)

  mov $1, %rax
  mov %rax, %rdi
  mov %rbp, %rsi
  sub $0xd, %rsi
  mov $13, %rdx
  syscall
	mov $231, %rax
  xor %rdi, %rdi
  syscall
