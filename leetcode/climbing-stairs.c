int climbStairs(int n){
  int cur, pre;
  
  if (n == 0 || n == 1)
    return 1;
  
  pre = 1;
  cur = 2;
  int tmp; 
  
  for (int i = 3; i <= n; i++) {
    tmp = cur + pre;
    pre = cur;
    cur = tmp;
  }
  
  return cur;
}
