int isBalanced(BinaryTreeNode<int>* root){
    if(!root) return 0;
    
    int leftHeight = isBalanced(root->left);
    if(leftHeight == -1)
        return -1;

    int rightHeight = isBalanced(root->right);
    if(rightHeight == -1)
        return -1;
        
    if(abs(leftHeight - rightHeight) > 1)
        return -1;
    
    return max (leftHeight, rightHeight) + 1;
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    int ans = isBalanced(root);
    if(ans == -1)
        return false;
    return true;
}
