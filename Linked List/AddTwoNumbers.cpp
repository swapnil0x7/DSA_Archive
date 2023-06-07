#include <bits/stdc++.h>

Node *addTwoNumbers(Node *A, Node *B)
{
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    int carry = 0;
    
    while(A or B or carry != 0){
        int sum = 0;

        if(A){
            sum += A->data;
            A = A->next;
        }    
        if(B){
            sum += B->data;
            B = B->next;
        }    

        sum += carry;                                 // line 21 to 27 must be in the exact order! - first add the total sum including carry,
                                                      // then modify the carry.
        Node* newNode = new Node(sum % 10);
        temp->next = newNode;
        temp = temp->next;
        
        carry = sum/10;
    }
    return dummy->next;
}

// Take this example, it covers all the edge cases. 👇
// A :  2 ->  4 ->  3 -> x
// B :  5 ->  6 ->  7 -> 9 -> x
