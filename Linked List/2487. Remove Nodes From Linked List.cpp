
// Space - O(N)
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

// Space - O(1)
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
        ListNode* curr = head;
        curr = reverseList(curr);
        int largestOnLeft = -1e9+7;

        ListNode* result = new ListNode(-1);
        ListNode* res = result;

        while(curr){
            if(curr->val >= largestOnLeft){
                largestOnLeft = curr->val;
                res->next = curr;
                res = res->next;
            }
            curr = curr->next;
        }
        res->next = NULL;
        result = reverseList(result->next);
        return result;
    }
};
