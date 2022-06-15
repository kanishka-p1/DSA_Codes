bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    if(root == NULL){
        return false;
    }
    
    if(root -> data == x){
        return true;
    }
    
    bool lSearch = isNodePresent(root -> left, x);
    if(lSearch == true){
        return true;
    }
    
    bool rSearch = isNodePresent(root -> right, x);
        if(rSearch == true){
            return true;
        }
    return false;
}
