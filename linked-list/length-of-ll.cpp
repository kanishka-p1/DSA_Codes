//length of linked list iteratively
int length(Node *head)
{
    //Write your code here
    int count = 0;
    Node *temp = head;
    while(temp  != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}


//length of linked list recursively
int length(Node *head) {
    // Write your code here
    if(head == NULL) {
        return 0;
    }
    else {
        return 1 + length(head->next);
    }
}
