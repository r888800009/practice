int max(int a, int b) 
{
  return a > b ? a : b;
}

void dfs(struct TreeNode* root, int *b, int *nb)
{
  if (root == NULL) {
    *b = *nb = 0;
    return;
  }
  
  int nlb, lb, nrb, rb;
    
  dfs(root->left, &lb, &nlb);
  dfs(root->right, &rb, &nrb);
  
  *b  = nlb + nrb + root->val;
  *nb = max(max(lb + rb, lb + nrb), max(nlb + rb, nlb + nrb));
    
  return; 
}

int rob(struct TreeNode* root)
{
  int b, nb;
  
  dfs(root, &b, &nb);
    
  return max(b, nb);
}
