void modifiedInorder(TreeNode<int>* root, int &count, int k, int &ans){
    if(!root) return;
    
    modifiedInorder(root->right, count, k, ans);
    
    count++;
    if(count == k){
        ans = root->data;
        return;
    }
    
    if(count < k) modifiedInorder(root->left, count, k, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1;
    int count = 0;
    modifiedInorder(root, count, k, ans);
    return ans;
}

//for Kth-largest, first go to the rightmost bottom node, then start incrementing count.
//This is why we call 'root->right' first.
