//Recursive
void preorder(TreeNode* root, vector<int> &res){ //helper fn
    if(!root) return;
    res.push_back(root->data);
    preorder(root->left, res);
    preorder(root->right, res);
}

vector<int> getPreOrderTraversal(TreeNode *root) 
{
    vector<int> res;
    if(!root) return res;
    preorder(root, res);
    return res;
}

//Iterative
vector<int> getPreOrderTraversal(TreeNode *root)
{
    stack<TreeNode* > s;
    vector<int> res;
    if(!root) 
        return res;
        
    s.push(root);

    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        res.push_back(curr->data);
        
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return res;
}