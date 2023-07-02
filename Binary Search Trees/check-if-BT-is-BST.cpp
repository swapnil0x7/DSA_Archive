bool checkBST(TreeNode* root, int minimum, int maximum){
    if(!root) return true;

    if(root->val < minimum or root->val > maximum) return false;

    return checkBST(root->left, minimum, root->val - 1) and checkBST(root->right, root->val + 1, maximum);  
}

int Solution::isValidBST(TreeNode* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}
