void rootToLeafPaths(TreeNode<int>* root, vector<vector<int>> &res, vector<int> &arr){
    
    if(!root)
        return;
    
    arr.push_back(root->data);

    if(!root->left and !root->right){
        res.push_back(arr);
        return;
    }
    rootToLeafPaths(root->left, res, arr);
    rootToLeafPaths(root->right, res, arr);
    
}



vector<int> allPathsFromRootToLeaf(TreeNode<int> *root)
{
    vector<vector<int>> res;
    vector<int> ans;
    rootToLeafPaths(root, res, arr);
    return res;
}
