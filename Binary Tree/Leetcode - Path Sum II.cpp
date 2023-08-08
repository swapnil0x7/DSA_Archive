vector<vector<int>> res;

void paths(TreeNode* root, int target, vector<int> &ans){
    if(!root)
        return;
    
    if(!root->left and !root->right){
        if(target - root->val == 0){
            ans.push_back(root->val);
            res.push_back(ans);
            ans.pop_back();
        }
        return;
    }
    ans.push_back(root->val);
    paths(root->left, target - root->val, ans);
    paths(root->right, target - root->val, ans);
    ans.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int target) {
    vector<int> ans;
    paths(root, target, ans);
    return res;
}
