//delete a node in linked list iteratively

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head == NULL) {
        return head;
    }
    
    Node *temp = head;
    
    if(pos == 0) {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    
    int count = 0;
    
    while(count < pos - 1 && temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    if(temp == NULL || temp->next == NULL) {
        return head;
    }
    
    if(temp != NULL) {
        Node *a = temp->next;
        temp->next = a->next;
        a->next = NULL;
        delete a;
    }
    
    return head;
}


//delete a node in a linked list recursively

Node *deleteNodeRec(Node *head, int position) {
	//Write your code here
    Node *temp = head;
    if(head ==NULL){
        return NULL;
    }
    
    if(position == 0){
        head = head -> next;
        delete(temp);
        return head;
    }
    head -> next = deleteNodeRec(head -> next, position - 1);
    return head;
}
