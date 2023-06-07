#include <bits/stdc++.h> 

LinkedListNode<int> *reverseList(LinkedListNode<int> *head) {
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

bool isPalindrome(LinkedListNode<int> *head) {
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkedListNode<int> *curr1 = head;
    LinkedListNode<int> *temp = slow;
    LinkedListNode<int> *curr2 = reverseList(temp);
    
    while(curr1 and curr2){
        if(curr1->data != curr2->data)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;

}
