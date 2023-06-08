#include <bits/stdc++.h> 

//Ceil in BST
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

//Floor in BST
int floorInBST(TreeNode<int> * root, int x)
{
    int floor = -1;
    while(root){
        if(root->val == x)
            return root->val;
        if(root->val < x){
            floor = root->val;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
}
