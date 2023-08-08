// O(1) space
Node* copyRandomList(Node* head) {
    if(!head) return NULL;
    Node* curr = head;

    while(curr){
        Node* newNode = new Node(curr->val);
        Node* nxt = curr->next;
        curr->next = newNode;
        newNode->next = nxt;
        curr = nxt;
    }

    curr = head;
    while(curr){
        Node* nxt = curr->next->next;
        curr->next->random = (curr->random != NULL) ? curr->random->next : NULL;
        curr = nxt;
    }
    
    curr = head;
    Node* dummy = new Node(-1);
    dummy->next = curr->next;

    while(curr){
        Node* nxt = curr->next->next;
        if(nxt) curr->next->next = nxt->next;
        curr->next = nxt;
        curr = nxt;
    }
    return dummy->next;
}




// O(N) space using hashmap
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node* > mp;
    Node* curr = head;

    while(curr){
        Node* copy = new Node(curr->val);
        mp[curr] = copy;
        curr = curr->next;
    }

    curr = head;

    while(curr){
        Node* temp = mp[curr];
        temp->next = mp[curr->next];
        temp->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}
