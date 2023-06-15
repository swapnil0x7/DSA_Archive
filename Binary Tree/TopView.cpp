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

//Recursive
void topView(TreeNode<int>* root, int height, int level, map<int,pair<int,int>> &mp){
    if(!root) return;
    
    if(mp.find(level) == mp.end()){                                             //we must maintain the vertical level and height.
        mp[level] = {root->val, height};
    }
    else if(mp[level].second >= height){
        mp[level] = {root->val, height};
    }
    topView(root->left, height+1, level-1, mp);
    topView(root->right, height+1, level+1, mp);
}

vector<int> getTopView(TreeNode<int> *root) {
    map<int, pair<int,int>> mp;
    vector<int> res;
    topView(root,0, 0, mp);
    
    for(auto i: mp){
        res.push_back(i.second.first);
    }
    return res;
}
