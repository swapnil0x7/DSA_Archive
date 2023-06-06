
// Recursive (easy)
void leftView(TreeNode *root, int level, int &maxLevel, vector<int> &res) {
    if(root==NULL) return ;
    if(level == maxLevel) {         // you can also use : if(level == res.size())
        res.push_back(root->val);
        maxLevel++;
    }
    leftView(root->left, level + 1, maxLevel, res);         //for right-view line 10 will come first.
    leftView(root->right, level + 1, maxLevel, res);
}
    
vector<int> leftSideView(TreeNode *root) {
    vector<int> res;
    int maxLevel = 0;
    leftView(root, 0, maxLevel, res);
    return res;
}

//Iterative
vector<int> getLeftView(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    q.push(root);
    vector<int> res;
    
    if(!root)
        return res;
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i=0;i<size;i++){
            TreeNode<int>* curr = q.front();
            q.pop();
            
            if(i==0)                                //for right-view i==size-1
                res.push_back(curr->data);
            if(curr->left) 
                q.push(curr->left);
            if(curr->right) 
                q.push(curr->right);
        }
    }
    return res;
}