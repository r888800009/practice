#include <stdio.h>
// gcc -m32 out_of_range.c -o out_of_range -no-pie

void shellcode_win() { system("cmd"); }

void shellcode_unix() { system("/bin/sh"); }

void index_out() {
  size_t array[1];
  int index;

  printf("Give me index\n");
  fflush(stdout);
  scanf("%d", &index);

  printf("Give me return address\n");
  fflush(stdout);
  scanf("%p", &array[index]);
}

void win10_hint() { shellcode_win(); }

int main() {
  printf("hint1: %p\n", shellcode_win);
  printf("hint2: %p\n", shellcode_unix);
  printf("hint3: %p\n", win10_hint);
  index_out();
  return 0;
}

