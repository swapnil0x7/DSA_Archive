bool pathSum(TreeNode* root, int total, int sum){
    if(!root) return false;
    
    if(!root->left and !root->right){
        total += root->val;
        return(total == sum);
    }
    return pathSum(root->left, total+root->val, sum) or pathSum(root->right, total+root->val, sum);
}

int Solution::hasPathSum(TreeNode* A, int B) {
    if (pathSum(A, 0, B) == true){
        return 1;
    }
    return 0;
}
