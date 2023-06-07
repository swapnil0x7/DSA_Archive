Node *firstNode(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){               //there is a loop.
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;                        //there is no loop.
}
