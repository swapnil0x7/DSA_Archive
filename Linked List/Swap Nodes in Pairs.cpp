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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = new ListNode(-1);
        ListNode* prev = temp;
        prev->next = head;

        while(curr and curr->next){
            ListNode* NEXT = curr->next;
            curr->next = NEXT->next;
            NEXT->next = curr;

            prev->next = NEXT;
            prev = curr;
            curr = curr->next;
        }
        return temp->next;

    }
};
