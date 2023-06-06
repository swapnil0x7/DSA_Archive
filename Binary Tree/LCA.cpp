#include <bits/stdc++.h> 

TreeNode<int>* lca(TreeNode<int>* root, int x, int y){
    if(!root or root->data == x or root->data == y)           // all nodes will return NULL if not x or y. (this is the main idea!)
        return root;
    
    TreeNode<int>* left = lca(root->left, x, y);
    TreeNode<int>* right = lca(root->right, x, y);
    
    if(!left)
        return right;
    if(!right)
        return left;
    else                          
        return root;
    
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int>* ans = lca(root, x, y);
    return ans->data;
}
