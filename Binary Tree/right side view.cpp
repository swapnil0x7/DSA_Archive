// Recursive
void inorder(TreeNode* root, int count, vector<int> &res){
    if(!root) return;

    if(count == res.size()){
        res.push_back(root->val);
    }
    inorder(root->right, count+1, res);
    inorder(root->left, count+1, res);
}

vector<int> Solution::solve(TreeNode* root) {
    vector<int> res;
    if(!root) return res;

    inorder(root, 0, res);
    return res;
}

//Iterative
vector<int> Solution::solve(TreeNode* root) {
    vector<int> res;
        if(root == NULL) return res;
        unordered_map<int, int> mp;
        queue<TreeNode* > q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                mp[level] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        
        for(int i=0;i<level;i++){
            res.push_back(mp[i]);
        }
        return res;
}
