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

// OR
  
void f(Node* root, vector<int> &ans, vector<vector<int>> &res){
    if(!root) return;
    ans.push_back(root->data);
    
    if(!root->left and !root->right) res.push_back(ans);
    
    f(root->left, ans, res);
    f(root->right, ans, res);
    
    ans.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> res;
    vector<int> ans;
    f(root, ans, res);
    return res;
}



vector<int> allPathsFromRootToLeaf(TreeNode<int> *root)
{
    vector<vector<int>> res;
    vector<int> ans;
    rootToLeafPaths(root, res, arr);
    return res;
}
