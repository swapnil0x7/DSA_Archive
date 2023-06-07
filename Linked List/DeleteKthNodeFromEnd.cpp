
Node* removeKthNode(Node* head, int K)
{
    //create and attach a dummy start node before head.
    Node* start = new Node(-1);
    start->next = head;
    
    Node* slow = start;
    Node* fast = start;
    
    //create a gap of 'K' nodes between slow and fast.
    for(int i=0;i<K;i++){
        fast = fast->next;
    }
    
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return start->next;
}

//The purpose of creating dummy node is evident when K == length of LL, try a test-case once!
