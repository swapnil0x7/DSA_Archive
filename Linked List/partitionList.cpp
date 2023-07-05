//Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.
//You should preserve the original relative order of the nodes in each of the two partitions.
// (Scaler)

ListNode* Solution::partition(ListNode* head, int k) { 
    ListNode* lesser = new ListNode(-1);
    ListNode* greater = new ListNode(-1);
    ListNode* l = lesser;
    ListNode* g = greater;

    ListNode* curr = head;

    while(curr){
        if(curr->val < k){
            l->next = curr;
            l = l->next;
            curr = curr->next;
        }
        else{
            g->next = curr;
            g = g->next;
            curr = curr->next;
        }
    }
    l->next = NULL;
    g->next = NULL;
    l->next = greater->next;
    return lesser->next;
}
