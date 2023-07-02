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

bool path(TreeNode* root, int target, vector<int> &p){
    if(!root) return false;
    
    if(root->val == target){
        p.push_back(root->val);
        return true;
    }

    if(path(root->left, target, p) or path(root->right, target, p)){
        p.push_back(root->val);
        return true;
    }
    return false;
}

//Approach two - takes extra space though
int Solution::lca(TreeNode* root, int x, int y) {
    vector<int> pathX;
    vector<int> pathY;

    path(root, x, pathX);
    path(root, y, pathY);

    int n = pathX.size() - 1;
    int m = pathY.size() -1;
    int ans = -1;

    while(n>=0 and m >=0){
        if(pathX[n] == pathY[m]){
            ans = pathX[n];
            n--;
            m--;
        }
        else break;
    }
    return ans;
}

