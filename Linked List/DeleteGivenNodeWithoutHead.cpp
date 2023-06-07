#include <bits/stdc++.h>

void deleteNode(LinkedListNode<int> * node) {           //time complexity -> O(1)
    
    LinkedListNode<int>* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}
