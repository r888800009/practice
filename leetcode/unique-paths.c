int uniquePaths(int m, int n){
  int dp[m];
  for (int i = 0; i < m; i++)
    dp[i] = 1;
  
  for (int x = 1; x < n; x++) {
    for (int y = 1; y < m; y++) 
      dp[y] = (int) ((unsigned long) dp[y] + dp[y - 1]);
  }
  
  return dp[m - 1];
}
