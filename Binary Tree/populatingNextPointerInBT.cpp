Node* connect(Node* root) {
      if(!root) return NULL;
  
      queue<Node*> q;
      q.push(root);
  
      while(!q.empty()){
          int length = q.size();
          Node* prev = NULL;
  
          for(int i=length-1;i>=0;i--){
              Node* curr = q.front(); q.pop();
  
              curr->next = prev;
              prev = curr;
              if(curr->right) q.push(curr->right);
              if(curr->left) q.push(curr->left);
          }
      }
      return root;
}
