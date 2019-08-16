class Solution {
  map<int, int> table;
public:
    int majorityElement(vector<int>& nums) {
      if (nums.size() == 0)
        return 0;
      
      for (int i = 0; i < nums.size(); i++) {
        if (table.find(nums[i]) == table.end()) 
          table[nums[i]] = 1;
        else 
          table[nums[i]]++;
      } 
      
      int time = 0, val;
      
      for (auto it : table) {
        if (it.second > time) {
          time = it.second;
          val = it.first;
        }
      }
        
      return val;
    }
};
