https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

my sol - 

#include <bits/stdc++.h> 

Node *removeDuplicates(Node *head)
{
    unordered_set<int> s;
    Node* curr = head;
    Node* prev = NULL;
  
    while(curr){
        if(s.find(curr->data) != s.end()){
            prev->next = curr->next;
        }
        else{
            s.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}
