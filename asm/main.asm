; vim: set ft=nasm :
; nasm -f elf64 main.asm
; gcc -no-pie main.o

SECTION .data
output: db "%d", 0xa, 0

SECTION .text
global main
extern printf

main:
    ; Prologue
    push rbp
    mov rbp, rsp

    ; arithmetic left shift
    mov rdi, output
    xor rax, rax

    mov rsi, 11
    sal rsi, 30

    call printf

    ; logic left shift
    mov rdi, output
    xor rax, rax

    mov rsi, 11
    shl rsi, 30

    call printf

    ; Epilogue
    mov rsp, rbp
    pop rbp
    ret
