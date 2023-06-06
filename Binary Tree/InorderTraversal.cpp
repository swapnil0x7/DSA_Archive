//Recursive
void inorder(TreeNode* root, vector<int> &res){     //helper fn
    if(!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    if(!root) return res;
    inorder(root, res);
    return res;

}

//Iterative
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode*> s;
    
    TreeNode* curr = root;

    while(true){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        else{
            if(s.empty()) break;
            curr = s.top();
            s.pop();
            res.push_back(curr->data);
            curr = curr->right;
        }
    }
    return res;
}