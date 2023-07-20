int isSumTree(TreeNode* root){
    if(!root) return 0;
    if(!root->left and !root->right) return root->val;

    int left = isSumTree(root->left);
    int right = isSumTree(root->right);

    if(left == -1 or right == -1) return -1;

    if(root->val != left + right){
        return -1;
    }
    return root->val+left+right;
}

int Solution::solve(TreeNode* root) {
    if(!root) return 1;
    
    if(isSumTree(root) != -1)
        return 1;
    else
        return 0;
}
