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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;

        while(curr){
            while(!s.empty() and s.top()->val < curr->val){
                s.pop();
            }
            s.push(curr);
            curr = curr->next;
        }

        ListNode* result = new ListNode(-1);
        ListNode* res = result;

        while(!s.empty()){
            res->next = s.top();
            s.pop();
            res = res->next;
        }
        res->next = NULL;
        result = reverseList(result->next);
        return result;
    }
};
