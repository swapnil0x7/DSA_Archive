void f(TreeNode* root, int largestTillNow, int &count){
    if(!root) return;

    if(root->val >= largestTillNow)
        count++;
    
    largestTillNow = max(root->val, largestTillNow);
    f(root->left, largestTillNow, count);
    f(root->right, largestTillNow, count);
}


int goodNodes(TreeNode* root) {
    int count = 0;
    f(root, root->val, count);
    return count;
}
