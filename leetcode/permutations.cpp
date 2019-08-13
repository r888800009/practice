class Solution {
  vector<vector<int>> result; 
  vector<int> tmp;
  vector<int> nums;
  vector<bool> mark;
  
  void recursion(){
    if (nums.size() == tmp.size()) {
      result.push_back(tmp);
      return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
      if (mark[i])
        continue;
      
      tmp.push_back(nums[i]);
      mark[i] = true;
      recursion();
      tmp.pop_back();   
      mark[i] = false;
    }
  }  
  
public:
  vector<vector<int>> permute(vector<int> &nums) {
    mark = vector<bool>(nums.size());
    std::fill(mark.begin(), mark.end(), false);
    
    this->nums = nums;
    recursion();
    
    return result;
  }
};
