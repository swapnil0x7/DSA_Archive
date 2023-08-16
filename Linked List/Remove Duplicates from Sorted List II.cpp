ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* prev = dummy;
      ListNode* curr = head;
  
      while(curr){
          if(curr->next and curr->val == curr->next->val){
              while(curr->next and curr->val == curr->next->val)
                  curr = curr->next;
              prev->next = curr->next;
          }
          else{
              prev = curr;
          }
          curr = curr->next;
      }
      return dummy->next;
}
