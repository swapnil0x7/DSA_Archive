ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        int l1 =0; int l2 =0;
        while(curr1){
            curr1 = curr1->next;
            l1++;
        }
        while(curr2){
            curr2 = curr2->next;
            l2++;
        }
        curr1 = headA;
        curr2= headB;
        
        while(l1>l2){
            curr1 = curr1->next;
            l1--;
        }
        while(l1<l2){
            curr2 = curr2->next;
            l2--;
        }
        
        while(curr1 and curr2){
            if(curr1 == curr2) return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
}
