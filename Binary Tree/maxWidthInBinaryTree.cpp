int getMaxWidth(TreeNode<int> *root)
{
    if(!root)
        return 0;
    
    int maxWidth = 0;
    queue<TreeNode<int>*> q;
    q.push(root);


    while(!q.empty()){
        int width = q.size();
        maxWidth = max(maxWidth, width);

        for(int i=0;i<width;i++){
            TreeNode<int>* curr = q.front();
            q.pop();

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);

        }
    }
    return maxWidth;
}