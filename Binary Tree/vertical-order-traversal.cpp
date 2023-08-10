
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    vector<vector<int>> res;
    map<int, vector<int>> mp;

    queue<pair<int, TreeNode*>> q;
    q.push({0, root});

    while(!q.empty()){
        TreeNode* curr = q.front().second;
        int level = q.front().first;
        q.pop();

        mp[level].push_back(curr->val);

        if(curr->left){
            q.push({level - 1, curr->left});
        }
        if(curr->right){
            q.push({level + 1, curr->right});
        }
    }
    for(auto v: mp){
        res.push_back(v.second);
    }
    return res;
}
