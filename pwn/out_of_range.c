#include <stdio.h>
// gcc -m32 out_of_range.c -o out_of_range -no-pie

void shellcode_win() { system("cmd"); }

void shellcode_unix() { system("/bin/sh"); }

void index_out() {
  int array[1];
  int index;

  printf("Give me index\n");
  fflush(stdout);
  scanf("%d", &index);

  printf("Give me return address\n");
  fflush(stdout);
  scanf("%u", &array[index]);
}

int main() {
  index_out();
  return 0;
}

