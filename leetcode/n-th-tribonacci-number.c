int dp[38] = {0}; 

int tribonacci(int n){
  if (n == 0)
    return 0;
  
  if (n == 1 | n == 2)
    return 1;
  
  if (dp[n] != 0)
    return dp[n];
  
  return dp[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1) ;
}
