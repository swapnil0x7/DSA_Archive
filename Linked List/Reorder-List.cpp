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
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slow = head, *fast = head;

        while(fast and fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head, *prev = NULL;
        while(curr){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* middle = findMiddleNode(head);
        ListNode* second = middle->next;
        middle->next = NULL;
        
        second = reverseList(second);
        ListNode* first = head;

        while(first){
            cout<<first->val<<" ";
            first = first->next;
        }
        cout<<endl;
        while(second){
            cout<<second->val<<" ";
            second = second->next;
        }

        // while(second){
        //     ListNode* NEXT = first->next;
        //     first->next = second;
        //     first = NEXT;
        //     second = second->next;
        // }
    }
};
