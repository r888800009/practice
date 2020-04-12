#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  a = (a - 1) / 2;
  b = b / 2;
  printf("%d\n", b * (b + 1) - a * (a + 1));
}

