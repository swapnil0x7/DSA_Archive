#include <bits/stdc++.h>

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first)
        return second;
    if(!second)
        return first;

    Node<int>* curr = new Node<int>(-1);
    Node<int>* temp = curr;
    
    while(first and second){
        if(first->data <= second->data){
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
        else{
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }   
    while(first){
        temp->next = first;
        temp = temp->next;
        first = first->next;
    }
    while(second){
        temp->next = second;
        temp = temp->next;
        second = second->next;
    }
    return curr->next;
}
