void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    
    BinaryTreeNode<int>* swap;
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
    
    swap = root -> left;
    root -> left = root -> right;
    root -> right = swap;
}
