vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if(!root) return res;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            maxi = max(maxi, curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        res.push_back(maxi);
    }
    return res;
}
