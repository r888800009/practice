class Solution {
  int ans = 0;

  int max(int a, int b)
  {
    return a > b ? a : b;
  }

  // count max node
  int dfs(TreeNode *root)
  { 
    if (root == NULL)
      return 0;
    
    int l, r;
    l = dfs(root->left);
    r = dfs(root->right);
   
    ans = max(ans, l + r);
    return max(l, r) + 1;
  }

public:
    int diameterOfBinaryTree(TreeNode *root) {
      dfs(root);
      return ans; 
    }
};
