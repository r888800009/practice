#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 gcc taint.c -no-pie
*/

char source[30];
char sink[20];
char temp[20];

void mycpy(char *destination, const char *source, size_t num) {
  for (int i = 0; i < num; i++) {
    destination[i] = source[i];
  }
}

void copy() {
  strncpy(temp, source, 14);
  mycpy(sink, temp, 14);
  puts(sink);
}

int main(int argc, char *argv[]) {
  copy();
  return 0;
}
