//serialize
vector<int> Solution::solve(TreeNode* root) {
    queue<TreeNode* > q;
    q.push(root);
    vector<int> res;

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if(curr == NULL){
            res.push_back(-1);
            continue;
        }
        else{
            res.push_back(curr->val);
        }
        q.push(curr->left);
        q.push(curr->right);
    }
    return res;
}


// Deserialize 
TreeNode* Solution::solve(vector<int> &arr) {
    int n = arr.size();
    queue<TreeNode* > q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int idx = 1;

    while(!q.empty() and idx < n){
        TreeNode* curr = q.front();
        q.pop();

        if(arr[idx] != -1) 
            curr->left = new TreeNode(arr[idx]);
        q.push(curr->left);
        idx++;
        if(arr[idx] != -1) 
            curr->right = new TreeNode(arr[idx]);
        q.push(curr->right);
        idx++;
    }
    return root;
}
