;jwasm -elf64 jwasm.asm
;gcc jwasm.o
.data

.code

main:
  mov eax,5
  add eax,6
  ret
  end main
