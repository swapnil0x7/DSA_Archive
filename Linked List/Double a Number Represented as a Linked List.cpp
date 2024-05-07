ListNode* reverseLL(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = reverseLL(head);
        ListNode *curr = newHead, *prev = NULL;
        int carry = 0;

        while(curr){
            int newValue = curr->val * 2 + carry;
            if(newValue >= 10)
                carry = 1;
            else
                carry = 0;

            curr->val = newValue % 10;
            prev = curr;
            curr = curr->next;
        }

        if(carry){
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        curr = newHead;
        return reverseLL(curr);
    }
