#include <bits/stdc++.h>

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prev = NULL;

    while(curr){
        LinkedListNode<int>* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
    
}