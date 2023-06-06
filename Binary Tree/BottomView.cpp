//Iterative
vector<int> bottomView(BinaryTreeNode<int> * root){

    queue<pair<BinaryTreeNode<int>*, int>> q;
    map<int,int> mp;
    vector<int> res;

    q.push({root, 0});
    
    while(!q.empty()){
        BinaryTreeNode<int> * curr = q.front().first;
        int level = q.front().second;
        q.pop();

        mp[level] = curr->data;
        
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

