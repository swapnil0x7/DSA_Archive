//Recursive
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	if(!root) return NULL;
    
    if(root->data < P->data and root->data < Q->data)
        return LCAinaBST(root->right, P, Q);
    
    if(root->data > P->data and root->data > Q->data)
        return LCAinaBST(root->left, P, Q);
        
    return root;
}

//Iterative (more space efficient)
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    TreeNode<int>* curr = root;
    
    while(curr){
        if(curr->data > P->data && curr->data > Q->data) 
          curr = curr->left;
      
        else if(curr->data < P->data && curr->data < Q->data) 
          curr = curr->right;
      
        else return curr;
    }

    return NULL;
}
