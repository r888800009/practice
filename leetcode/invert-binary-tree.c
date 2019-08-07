struct TreeNode* invertTree(struct TreeNode* root){
  if (root == NULL)
    return NULL;
  
  struct TreeNode* tmp = invertTree(root->right);  
  root->right = invertTree(root->left);  
  root->left = tmp;  
  
  return root;
}
