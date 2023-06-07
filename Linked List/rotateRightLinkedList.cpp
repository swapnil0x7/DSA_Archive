
Node *rotate(Node *head, int k) {

	int length = 1;
	Node* curr = head;

	while(curr->next){
		length++;
		curr = curr -> next;
	}
	k = k%length;
	
	if(k == length) return head;                    //edge case: when k == length, list remains unchanged    

	curr->next = head;                              //make list circular
	curr = head;

	int n = length-k;
	for(int i=1;i<n;i++){
		curr = curr->next;
	}
	Node* temp = curr->next;
	curr->next = NULL;                              //break list at k nodes from the end.
	return temp;

}
