#include <stdbool.h>
#include <stdio.h>

bool check(int n, int array[n][n]) {
  int count = 0, pre = 0;

  for (int x = 0; x < n; x++) pre += array[x][0];

  // rows
  for (int y = 1; y < n; y++) {
    count = 0;
    for (int x = 0; x < n; x++) count += array[x][y];
    if (pre != count) return false;
  }

  // columns
  for (int x = 0; x < n; x++) {
    count = 0;
    for (int y = 0; y < n; y++) count += array[x][y];
    if (pre != count) return false;
  }

  count = 0;
  for (int i = 0; i < n; i++) count += array[i][i];
  if (pre != count) return false;

  count = 0;
  for (int i = 0; i < n; i++) count += array[n - 1 - i][i];
  if (pre != count) return false;

  return true;
}

int main() {
  int n;

  printf("n: ");
  scanf("%d", &n);
  n = 1 + n * 2;
  printf("%d\n", n);

  int array[n][n];
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) array[x][y] = -1;
  }

  int m = 1;
  int x = n / 2, y = 0;
  while (n * n >= m) {
    array[x][y] = m;
    m++;

    x = (x + 1) % n;
    y = (n + y - 1) % n;

    if (array[x][y] != -1) {
      y = (y + 2) % n;
      x = (n + x - 1) % n;
    }
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) printf("%5d", array[x][y]);
    printf("\n");
  }

  if (!check(n, array)) printf("False\n");

  return 0;
}
