#include <stack>

class Solution {
  std::stack<TreeNode *> stack;
  
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode *cur = root; 
    
    while (cur != NULL || stack.size() > 0) {
      while (cur != NULL) {
        stack.push(cur);
        cur = cur->left;
      }
      
      cur = stack.top();
      stack.pop();
      result.push_back(cur->val);
      cur = cur->right; 
    }
     
    return result;
  }
};
