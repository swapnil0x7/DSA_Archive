// The sumTree fn. returns 👇
// -1: not a sumTree,
// 0: root is null,
// sum: root->data  + left subtree sum + right subtree sum,


int sumTree(Node* root){
        if(!root) return 0;
        if(!root->left and !root->right) return root->data;
        
        int left = sumTree(root->left);
        if(left == -1) return -1;
        
        int right = sumTree(root->right);
        if(right == -1) return -1;
        
        if(root->data == left + right) 
            return left + right + root->data; 
        
        return -1;
    }
    
    bool isSumTree(Node* root)
    {
         int sum = sumTree(root);
         return (sum == -1) ? false : true;
    }
