class BSTiterator
{
      stack<TreeNode<int>*> s;
  public:
      
      BSTiterator(TreeNode<int> *root) {
          pushAll(root);
      }

      int next() {
          TreeNode<int>* latestNode = s.top();
          s.pop();
          pushAll(latestNode->right);             //check for the nodes in its right!
          return latestNode->data;
      }

      bool hasNext() {
          return !s.empty();
      }
  
      void pushAll(TreeNode<int>* root) {
          while(root){
              s.push(root);
              root = root->left;
          }
      }
};
