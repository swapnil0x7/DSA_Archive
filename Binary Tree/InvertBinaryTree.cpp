//Iterative (level order)
TreeNode* invertTree(TreeNode* root) {
      if (!root)  return NULL;
      
      queue<TreeNode*> q;
      q.push(root);
  
      while (!q.empty()) {
          TreeNode* node = q.front();
          q.pop();

          TreeNode* left = node->left;        //swapping left and right nodes of current node
          node->left = node->right;
          node->right = left;

          if (node -> left)   q.push(node -> left);
          
          if (node -> right)  q.push(node -> right);
          
      }
      return root;
}

//Recursive (less efficient as it may cause stack overflow due to recursion for big tree)
TreeNode* invertTree(TreeNode* root) {
      if(!root) return NULL;

      TreeNode* left = invertTree(root->left);
      TreeNode* right = invertTree(root->right);

      swap(root->left, root->right);
      return root;
}
