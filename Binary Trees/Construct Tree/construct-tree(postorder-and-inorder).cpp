BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength - 1]);
    
    if(postLength == 1){
        return root;
    }
    if(postLength == 0){
        return NULL;
    }
    
    int i = 0;
    while(inorder[i] != postorder[postLength - 1]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength - i - 1;
    
    root -> left = buildTree(postorder, left_size, inorder, left_size);
    root -> right = buildTree(postorder + left_size, right_size, inorder + left_size + 1, right_size);
    
    return root;
}
