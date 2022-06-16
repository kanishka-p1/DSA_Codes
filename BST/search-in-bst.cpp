bool searchInBST(BinaryTreeNode<int> *root , int k) {
	// Write your code here
    if(root == NULL){
        return NULL;
    }
    
    if(root -> data == k){
        return true;
    }
    if(root -> data > k){
        searchInBST(root -> left, k);
    }
    else{
        searchInBST(root -> right, k);
    }
    
}
