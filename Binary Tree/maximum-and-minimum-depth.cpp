//Maximum depth of the binary tree.
int maxDepth(TreeNode* root) {
      if(!root) return 0;

      int left = maxDepth(root->left);
      int right = maxDepth(root->right);

      return max(left, right) + 1;
}



//Minimum depth of the binary tree.
int minDepth(TreeNode* root) {
    if(!root) return 0;

    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left),minDepth(root->right));
}
