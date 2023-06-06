#include <bits/stdc++.h> 

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int>*> q;
    vector<int> res;
    if(!root) return res;

    q.push(root);
    bool flag = true;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* curr = q.front();
            q.pop();
            
            int index = (flag) ? i : size-1-i;            //just use a flag and change the indexing pattern for zigzag traversal
            temp[index] = curr->data; 
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        for(auto i: temp){
            res.push_back(i);
        }
        flag = !flag;
    }
    return res;
}
