//Recursive
void postOrder(TreeNode* root, vector<int> &res){       //helper fn
    if(!root) return;
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> res;
    if(!root) return res;
    postOrder(root, res);
    return res;

}