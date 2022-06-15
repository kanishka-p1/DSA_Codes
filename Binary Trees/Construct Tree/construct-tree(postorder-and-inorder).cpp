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

            *********************************************************************************************************************************************
            
BinaryTreeNode<int>* buildTreeHelper(int* in, int* post, int is, int ie, int ps, int pe) {
    if(is > ie) {
        return NULL;
    }
    
    int rootdata = post[pe];
    int rootindex = -1;
    for(int i = is; i <= ie; i++) {
        if(in[i] == rootdata) {
            rootindex = i;
            break;
        }
    }
    int lins = is;
    int line = rootindex - 1;
    int lposts = ps;
    int lposte = rootindex - 1 - is + ps;
    int rins = rootindex + 1;
    int rine = ie;
    int rposts = ps + rootindex - is;
    int rposte =  pe - 1;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = buildTreeHelper(in, post, lins, line, lposts, lposte);
    root->right = buildTreeHelper(in, post, rins, rine, rposts, rposte);
  return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildTreeHelper(inorder, postorder, 0, postLength - 1, 0, postLength - 1);
}
