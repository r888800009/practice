bool dfs(struct TreeNode* root, int sum) 
{
  if (root == NULL)
    return false;
  
  if (root->left == NULL && root->right == NULL)
    return sum == root->val;
  
  if (dfs(root->left, sum - root->val))
    return true;
  
  if (dfs(root->right, sum - root->val))
    return true;
  
  return false;
}

bool hasPathSum(struct TreeNode* root, int sum)
{
  if (root == NULL)
    return false;
  
  return dfs(root, sum);
}
