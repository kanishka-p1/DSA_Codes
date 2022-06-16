Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root == NULL){
        return NULL;
    }
    Node<int> *a = new Node<int>(root -> data);
    Node<int> *left = constructLinkedList(root -> left);
    
    if(left == NULL){
        left = a;
    }
    else{
        Node<int> *temp = left;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = a;
    }
    Node<int> *right = constructLinkedList(root -> right);
    if(right == NULL){
        a -> next = NULL;
    }
    else{
        a -> next = right;
    }
    return left;
}
