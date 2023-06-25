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

    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& arr) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] != NULL) pq.push(arr[i]);            //make sure any starting node of list is not NULL
        }

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();

            curr->next = temp;
            curr = curr->next;
            if(temp->next) pq.push(temp->next);
        }
        return head->next;
    }
};
