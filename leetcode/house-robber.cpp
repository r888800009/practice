class Solution {
  int max(int a, int b) {
    return a > b ? a : b;
  }
public:
  int rob(vector<int>& nums) {
    int robing = 0, notRobing = 0;
    
    for (int i = nums.size() - 1; i >= 0; i--) {
      int tmpR, tmpNR;
      
      tmpNR = max(notRobing, robing);
      tmpR = notRobing + nums[i];
      robing = tmpR;
      notRobing = tmpNR;
    }
      
    return max(robing, notRobing);
  }
};
