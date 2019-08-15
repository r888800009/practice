class Solution {
  int max(int a, int b) {
    return a > b ? a : b;
  }
  
  int min(int a, int b) {
    return a < b ? a : b;  
  }
  
  int divideAndConquer(vector<int>& nums, int left, int right, int &sumMax, int &sumMin) {
    if (left == right)
      return sumMin = sumMax = nums[left];
      
    int ans;
    int sumMaxL, sumMinL, sumMaxR, sumMinR;
    int mid = (left + right) / 2;
    
    ans = divideAndConquer(nums, left, mid, sumMaxL, sumMinL);
    ans = max(divideAndConquer(nums, mid + 1, right, sumMaxR, sumMinR), ans);
    ans = max(sumMaxR - sumMinL, ans);
     
    sumMin = min(sumMinL, sumMinR);
    sumMax = max(sumMaxL, sumMaxR);
    
    return ans;
  }
  
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0)
      return INT_MIN;
    
    // count prefix sum
    for (int i = 1; i < nums.size(); i++)
      nums[i] += nums[i - 1];
    
    int max, min;
    
    return divideAndConquer(nums, 0, nums.size() - 1, max, min);
  }
};
