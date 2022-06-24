//insert in linked list at ith position iteratively
Node* insertNode(Node *head, int i, int data) {
	// Write your code here  
   Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		/*Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;*/
    newNode->next = temp->next;
    temp->next = newNode;
	}
  
  
  //insert in linked list at ith position recursively
  Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL) {
        return head;
    }
    
    if(i == 0) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    head->next = insertNode(head->next, i - 1, data);
    return head;
}
