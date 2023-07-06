ListNode* reverseList(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;

    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* Solution::reverseBetween(ListNode* head, int B, int C) {
    if(!head) return NULL;

    ListNode* prev = NULL;
    ListNode* start = NULL;
    ListNode* end = NULL;
    ListNode* end_next = NULL;
    
    ListNode* curr = head;
    int i=1;
    while(curr){
        if(i<B) prev = curr;

        if(i==B) start = curr;
        
        if(i==C){
            end = curr;
            end_next = curr->next;
        }
        i+=1;
        curr = curr->next;
    }

    end->next = NULL;

    end = reverseList(start);
    
    start->next = end_next;
    
    if(prev){
        prev->next = end;
    }
    else{
        head = end;
    }
    return head;
}
