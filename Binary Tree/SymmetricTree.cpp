bool symmetric(TreeNode* root1, TreeNode* root2){
    if(!root1 or !root2) 
        return root1==root2;
    
    return (root1->val == root2->val and symmetric(root1->left, root2->right) and symmetric(root1->right, root2->left));
}

int Solution::isSymmetric(TreeNode* root) {
    if(!root) return 1;
    return symmetric(root, root);
}
