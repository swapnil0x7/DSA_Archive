#include <bits/stdc++.h>

class BSTIterator {
        stack<BinaryTreeNode<int>*> s;
        bool before = false;                                            
    
    public:
        BSTIterator(BinaryTreeNode<int>* root, bool isBefore){
            before = isBefore;
            pushAll(root);
            
        }
        
        int next(){
            BinaryTreeNode<int>* curr = s.top();
            s.pop();
            
            if(before)
                pushAll(curr->left);
            else 
                pushAll(curr->right);
            
            return curr->data;
        }
        
        void pushAll(BinaryTreeNode<int>* root){
            while(root){
                s.push(root);
                if(before)
                    root = root->right;
                else 
                    root = root->left;       
            }    
        }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(!root) return false;
                                                            //The aim is to use two pointer approach for pair sum.
    BSTIterator smallest(root, false);                      //creating two inorder traversals, one in ascending sorted and 
    BSTIterator largest(root, true);                        //other in descending order
    
    int low = smallest.next(), high = largest.next();
    
    while(low < high){
        int total = low + high;
        if(total == k)
            return true;
        if(total < k)
            low = smallest.next();
        else
            high = largest.next();
    }
    return false;
}
