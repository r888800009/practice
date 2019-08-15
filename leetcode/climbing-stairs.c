int climbStairs(int n) {
  int cur, pre;

  if (n == 0 || n == 1) return 1;

  pre = 1;
  cur = 2;

  for (int i = 3; i <= n; i++) {
    int tmp;
    tmp = cur + pre;
    pre = cur;
    cur = tmp;
  }

  return cur;
}
