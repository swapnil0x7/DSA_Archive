#include <bits/stdc++.h>

int findSucc(BinaryTreeNode<int> *root, int key) {
    BinaryTreeNode<int>* curr = root;
    int ans = -1;
    while(curr){
        if(curr->data <= key)                  //the equal to (=) is important, because even if the node == key, we have to move right.
            curr = curr->right;
        else{
            ans = curr->data;
            curr = curr->left;
        }
    }
    return ans;
}

int findPred(BinaryTreeNode<int> *root, int key) {
    BinaryTreeNode<int>* curr = root;
    int ans = -1;
    while(curr){
        if(curr->data >= key)
            curr = curr->left; 
        else{
            ans = curr->data;
            curr = curr->right;
        }
    }
    return ans;
}



pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred = -1, succ = -1;
    
    pred = findPred(root, key);
    succ = findSucc(root, key);
    
    return make_pair(pred, succ);
    
}
