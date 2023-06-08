#include <bits/stdc++.h> 

//Iterative (efficient)
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    while(root){
        if(root->data == x)
            return true;
        if(root->data < x)
            root = root->right;
        else    
            root = root->left;
    }
    return false;
}


//Recursive
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(!root)
        return false;
    if(root->data == x)
        return true;
    if(root->data < x)
        searchInBST(root->right, x);
    else
        searchInBST(root->left, x);
}