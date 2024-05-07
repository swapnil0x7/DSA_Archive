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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr = head;

        for(int i=0;i<k-1;i++) curr = curr->next;
        ListNode* first = curr, *second = head;
        
        while(curr->next){
            second = second->next;
            curr = curr->next;
        }

        swap(first->val, second->val);
        return head;
    }
};
