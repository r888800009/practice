bool checkSubtree(struct TreeNode* left, struct TreeNode* right)
{
  if (left == NULL && right == NULL)
    return true;
  
  if (left == NULL || right == NULL)
    return false;
  
  if (left->val != right->val)
    return false;
    
  return checkSubtree(left->left, right->right) &&
         checkSubtree(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
  if (root == NULL)
    return true;   
  
  return checkSubtree(root->left, root->right);
}
