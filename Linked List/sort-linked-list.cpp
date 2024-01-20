class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* A, ListNode* B){
        if(!A) return B;
        if(!B) return A;

        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;

        while(A and B){
            if(A->val < B->val){
                curr->next = A;
                curr = A;
                A = A->next;
            }
            else{
                curr->next = B;
                curr = B;
                B = B->next;
            }
        }

        if(A) curr->next = A;
        if(B) curr->next = B;

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;

        ListNode *mid = findMiddle(head);
        ListNode *first = head, *second = mid->next;
        mid->next = NULL;

        first = sortList(first);
        second = sortList(second);

        return mergeList(first, second);
    }
};
