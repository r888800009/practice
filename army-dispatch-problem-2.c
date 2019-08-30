#include <limits.h>
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
  int n;
  int x, y, z;

  // first line
  scanf("%d %d %d %d", &n, &x, &y, &z);

  // load line 2
  int A[n], tmp, max_people = INT_MIN;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    A[i] = tmp;
    max_people = max(max_people, tmp);
  }

  // dp solve
  int pre, pre_people = A[0], cur_people;
  pre = pre_people * (x + y);
  for (int i = 1; i < n; i++) {
    if (y - z > 0)
      cur_people = A[i];
    else {
      if (A[i] > pre_people)
        cur_people = A[i];
      else
        cur_people = pre_people;
    }

    int diff = cur_people - pre_people;
    if (diff > 0)
      pre += diff * x;
    else
      pre += -diff * z;

    pre += cur_people * y;
    pre_people = cur_people;
  }

  printf("%d\n", pre);

  return 0;
}
