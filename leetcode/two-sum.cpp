#include <map>
#include <utility>       

class Solution {
  std::map<int, int> map; // val: index
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    std::map<int, int>::iterator it;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];  
      if ((it = map.find(diff)) == map.end())
        map.insert(std::pair(nums[i], i));
      else {
        result.push_back(it->second);
        result.push_back(i);
        break;
      }
    }

    return result;
  }
};
