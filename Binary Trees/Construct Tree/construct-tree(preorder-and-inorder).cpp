BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[0]);
    
    if(preLength == 1){
        return root;
    }
    if(preLength == 0){
        return NULL;
    }
    
    int i = 0;
    while(inorder[i] != preorder[0]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength - i - 1;
    
    BinaryTreeNode<int> *leftSubTree = buildTree(preorder + 1, left_size, inorder, left_size);
    BinaryTreeNode<int> *rightSubTree = buildTree(preorder + 1 + left_size, right_size, inorder + left_size + 1, right_size);
    
    root -> left = leftSubTree;
    root -> right = rightSubTree;
    
    return root;
}
