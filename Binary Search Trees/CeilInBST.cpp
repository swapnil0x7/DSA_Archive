#include <bits/stdc++.h> 

int findCeil(BinaryTreeNode<int> *root, int x){
    int ans = -1;
    while(root){
        if(root->data == x){
            ans = root->data;
            return ans;
        }
        if(root->data > x){
            ans = root->data;
            root = root->left;
        }
        else
            root = root->right;
    }
    return ans;
}
