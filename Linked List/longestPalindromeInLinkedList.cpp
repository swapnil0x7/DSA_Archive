int matchingCount(ListNode* left, ListNode* right){
    int count = 0;
    while(left and right){
        if(left->val == right->val) {
            count += 2;
            left = left->next;
            right = right->next;
        }
        else{
            break;
        }
    }
    return count;
}
int Solution::solve(ListNode* head) {
    ListNode* curr = head;
    ListNode* prev = NULL;
    int ans = 0;
    while(curr){
        ListNode* temp = curr->next;
        
        //checking for even
        int count = matchingCount(prev, curr);
        ans = max(ans, count);
        
        //checking for odd
        count = matchingCount(prev, temp);
        ans = max(ans, count + 1);
        
        curr->next = prev;                            //observe we are changing the next pointer of curr after calculation.
        prev = curr;
        curr = temp;
    }
    return ans;
}
