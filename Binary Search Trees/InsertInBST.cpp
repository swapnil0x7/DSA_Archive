//Iterative
TreeNode<int>* insertionInBST(TreeNode<int>* root, int x)
{
    TreeNode<int>* newNode = new TreeNode<int>(x);
  
    if(!root) return newNode;
  
    TreeNode<int>* curr = root;
    while(true){
        if(curr->val < x){
            if(!curr->right) {
                curr->right = newNode;
                break;
            }
            else curr = curr->right;
        }
        else{
            if(!curr->left){
                curr->left = newNode;
                break;
            }
            else curr = curr->left;
        }
    }
    return root;
}

//Recursive
TreeNode<int>* insertionInBST(TreeNode<int>* root, int x)
{
    if(!root) return new TreeNode<int>(x);
    
    if(root->val < x)
        root->right = insertionInBST(root->right, x);
    else
        root->left = insertionInBST(root->left, x);
}
