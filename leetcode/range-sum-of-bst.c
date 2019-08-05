int rangeSumBST(struct TreeNode *root, int L, int R){
  int sum = 0;
  
  if (root == NULL)
    return 0;
  
  if (root->val < L)
    sum = rangeSumBST(root->right, L, R);
  else if (root->val > R)
    sum = rangeSumBST(root->left, L, R);
  else if (root->val >= L && root->val <= R) {
    int sumL = 0, sumR = 0;
    sumL = rangeSumBST(root->left, L, R);
    sumR = rangeSumBST(root->right, L, R);
    sum = root->val + sumL + sumR;
  }

  return sum;
}
