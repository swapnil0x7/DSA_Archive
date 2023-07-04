void paths(Node* root, int sum, int &maxSum, int length, int &maxLength){
      if(!root){
          if(length > maxLength){
              maxLength = length;
              maxSum = sum;
          }
          else if(length == maxLength){
              maxSum = max(maxSum, sum);
          }
          return;
      }
      
      paths(root->left, sum + root->data, maxSum, length + 1, maxLength);
      paths(root->right, sum + root->data, maxSum, length + 1, maxLength);
}
    
int sumOfLongRootToLeafPath(Node *root)
{
      int maxSum = -1e9;
      int maxLength = 0;
      paths(root, 0, maxSum, 0, maxLength);
      return maxSum;
}
