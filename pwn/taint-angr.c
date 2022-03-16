#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 gcc taint-angr.c -no-pie -o taint-angr
*/

char source[30];
char sink[20];
char temp[20];

void copy() {
  int a;
  scanf("%d", &a);
  if (a == 0) {
	  strncpy(temp, source, 14);
	  strncpy(sink, temp, 14);
	  puts(sink);
  }
  else 
    return;
}

int main(int argc, char *argv[]) {
  copy();
  return 0;
}
