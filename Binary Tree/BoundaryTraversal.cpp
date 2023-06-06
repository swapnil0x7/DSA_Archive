#include <bits/stdc++.h> 

bool isLeaf(TreeNode<int>* root){
    return(!root->left and !root->right);
}

void leftBoundary(TreeNode<int>* root, vector<int> &res){
    
    while(root){
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        if(root->left) 
            root = root->left;
        else
            root = root->right;
    }
}

void leafNodes(TreeNode<int>* root, vector<int> &res){
    if(!root) return;
    if (isLeaf(root)) {
        res.push_back(root->data);
    }
    leafNodes(root->left, res);
    leafNodes(root->right, res);
}

void rightBoundary(TreeNode<int>* root, vector<int> &res){
    
    vector<int> temp;
    while(root){
        if(!isLeaf(root)){
            temp.push_back(root->data);
        }
        if(root->right) 
            root = root->right;
        else
            root = root->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    
    if(!isLeaf(root)) res.push_back(root->data);
    leftBoundary(root->left, res);
    leafNodes(root, res);
    rightBoundary(root->right, res);
  
    return res;
}
