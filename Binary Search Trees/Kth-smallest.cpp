void inorder(TreeNode<int>* root, int &count, int k, int &ans){
    if(!root) return;
    inorder(root->left, count, k, ans);
  
    count++;
    if(count == k) {
        ans = root->data;
        return;
    }
  
    if(count < k) inorder(root->right, count, k, ans);            //here, if-condition prevents further unnecessary recursive calls!
}

int kthSmallest(TreeNode<int> *root, int k)
{
    int count = 0;
    int ans = -1;
    inorder(root, count, k, ans);
    return ans;
}
