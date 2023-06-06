//Iterative
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;
    if(!root)
        return res;
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> mp;

    q.push({root, 0});

    while(!q.empty()){
        TreeNode<int>* curr = q.front().first;
        int level = q.front().second;
        q.pop();

        if(mp.find(level) == mp.end())
            mp[level] = curr->val;

        if(curr->left)
            q.push({curr->left, level-1});
        if(curr->right)
            q.push({curr->right, level+1});
    
    } 
    for(auto i: mp){
        res.push_back(i.second);
    }
    return res;
}