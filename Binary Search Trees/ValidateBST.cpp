#include <bits/stdc++.h> 

bool check(BinaryTreeNode<int>* root, int minimum, int maximum){
    if(!root) return true;
    if(root->data > maximum or root->data < minimum)
        return false;
    return check(root->left, minimum, root->data) and check(root->right, root->data, maximum);
}

bool validateBST(BinaryTreeNode<int> *root) {
    if(!root) return true;
    return check(root, INT_MIN, INT_MAX);
}

//the usage of INT_MIN and INT_MAX ensures that
//all elements to left and right of root node are smaller and greater that the root node respectively
