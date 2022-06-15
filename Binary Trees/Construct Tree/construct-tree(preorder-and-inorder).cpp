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

    *************************************************************************************************************************************************************

BinaryTreeNode<int>* buildTreeHelper(int *in, int* pre, int is, int ie, int ps, int pe) {
  if(is > ie) {
    return NULL;
  }
  
  int rootdata = pre[ps];
  int rootindex = -1;
  for(int i = is; i <= ie; i++) {
    if(in[i] == rootdata) {
      rootindex = i; break;
    }
  }
  int lins = is;
  int line = rootindex - 1;
  int lpres = ps + 1;
  int lpree = line - lins + lpres;
  int rpres = lpree + 1;
  int rpree = pe;
  int rins = rootindex + 1;
  int rine = ie;
  
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
  root->left = buildTreeHelper(in, pre, lins, line, lpres, lpree);
  root->right = buildTreeHelper(in, pre, rins, rine, rpres, rpree);
  return root;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
  return buildTreeHelper(inorder, preorder, 0, preLength - 1, 0, preLength - 1);
}
