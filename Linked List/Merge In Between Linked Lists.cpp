/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* A, int a, int b, ListNode* B) {
        ListNode *f=A,*s=A;
        for(int i=0;i<a-1;i++) f=f->next;
        
        for(int i=0;i<b;i++) s=s->next;
        
        f->next=B;
        
        while(B->next!=NULL) B=B->next;
        
        B->next=s->next;
        return A;
    }
};
