class Solution {
  std::stack<int> stack; 
  int min(int a, int b) {
    return a < b ? a : b;
  }
  
  int max(int a, int b) {
    return a > b ? a : b;
  }
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int l = nums.size(), r = 0;
    if (nums.size() == 0)
      return 0;
    
    for (int i = 0; i < nums.size(); i++) {
      while (!stack.empty() && nums[stack.top()] > nums[i]) {
        l = min(l, stack.top());
        stack.pop();
      }
      
      stack.push(i); 
    }
    
    while (!stack.empty())
      stack.pop();
    
    for (int i = nums.size() - 1; i >= 0; i--) {
      while (!stack.empty() && nums[stack.top()] < nums[i]) {
        r = max(r, stack.top());
        stack.pop();
      }
      
      stack.push(i); 
    }
    
    int result = r - l + 1;
    
    if (result < 0)
      result = 0; 
    
    return result;
  }
};
