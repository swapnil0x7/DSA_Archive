bool path(TreeNode<int>* root, int x, vector<int> &res){    //boolean fn to ensure no unnecessary recursion calls made
    if(!root)
        return false;
    
    res.push_back(root->data);
    
    if(root->data == x)
        return true;
    
    if(path(root->left, x, res) or path(root->right, x, res))
        return true;
    
    res.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> res;
    path(root, x, res);
    return res;
}
