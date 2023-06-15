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

//Recursive
void inorder(BinaryTreeNode<int>* root, int height, int level, map<int,pair<int,int>> &mp){
    if(!root) return;
    
    if(mp.find(level) == mp.end()){
        mp[level] = {root->data, height};
    }
    else if(mp[level].second <= height){
        mp[level] = {root->data, height};
    }
    inorder(root->left, height+1, level-1, mp);
    inorder(root->right, height+1, level+1, mp);
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int, pair<int,int>> mp;
    vector<int> res;
    inorder(root,0, 0, mp);
    
    for(auto i: mp){
        res.push_back(i.second.first);
    }
    return res;
}

