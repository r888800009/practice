class Solution {
  int sum = 0;
public:
  TreeNode* convertBST(TreeNode* root) {
    if (root == NULL) 
      return NULL;
    
    convertBST(root->right);
    root->val = sum += root->val;
    convertBST(root->left);
    
    return root;
  }
};
