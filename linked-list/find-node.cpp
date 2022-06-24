int findNode(Node *head, int n){
    // Write your code here.
    Node * temp = head;
    int count = 0;
   
    while(temp != NULL && n != temp -> data){
        temp = temp -> next;
        count ++;
    }
    if(temp == NULL){
        return -1;
    }
    return count;
}
