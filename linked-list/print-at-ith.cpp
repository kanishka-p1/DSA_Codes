void printIthNode(Node *head, int i)
{
    //Write your code here
    int count = 0;
    Node *tail = head;
    while(tail != NULL){
        if(count == i){
            cout << tail -> data << endl;
            return;
        }
        count++;
        tail = tail -> next;
    }
    return;
}
