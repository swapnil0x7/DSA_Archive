// Brute force - TC: O(N * M) + (N*M)log(N*M), SC: O(N)

#include<bits/stdc++.h>

Node* flattenLinkedList(Node* head) 
{
	vector<int> arr;
	Node* curr = head;

	while(curr){
		Node* temp = curr;
		while(temp){
			arr.push_back(temp->data);
			temp = temp->child;
		}
		curr = curr->next;
	}
	sort(arr.begin(), arr.end());

	Node* res = new Node(arr[0]);
	curr = res;

	for(int i=1;i<arr.size();i++){
		Node* newNode = new Node(arr[i]);
		curr ->child = newNode;
		curr = curr->child;
	}

	return res;

}

// Optimal Solution - TC: O(N+M) SC: O(1)  ->  N+M is total no. of nodes
Node* mergeList(Node* A, Node* B){
	Node* head = new Node(-1);
	Node* curr = head;
	Node* a = A, *b = B;

	while(a and b){
		if(a->data <= b->data){
			curr->child = a;
			curr = curr->child;
			a = a->child;
		}
		else{
			curr->child = b;
			curr = curr->child;
			b = b->child;
		}
	}
	while(a){
		curr->child = a;
		curr = curr->child;
		a = a->child;
	}
	while(b){
		curr->child = b;
		curr = curr->child;
		b = b->child;
	}
	return head->child;
}


Node* flattenLinkedList(Node* head) 
{
	if(!head or !head->next) return head;

	head->next = flattenLinkedList(head->next);

	Node* res = mergeList(head, head->next);

	return res;
}
