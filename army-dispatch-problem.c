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
  int dp[n][max_people + 1], pre_people = A[0], cur_people, min_money;
  dp[0][pre_people] = pre_people * (x + y);
  for (int i = 1; i < n; i++) {
    min_money = INT_MAX;
    for (int j = cur_people = A[i]; j <= max_people; j++) {
      int diff = j - pre_people;

      if (diff < 0)  // back
        dp[i][j] = dp[i - 1][pre_people] + z * -diff;
      if (diff > 0)  // send
        dp[i][j] = dp[i - 1][pre_people] + x * diff;
      // supply
      dp[i][j] += y * j;

      if (min_money > dp[i][j]) {
        min_money = dp[i][j];
        cur_people = j;
      }
    }

    pre_people = cur_people;
  }

  printf("%d\n", min_money);

  return 0;
}
