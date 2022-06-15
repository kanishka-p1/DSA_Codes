int height(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    
    int lh = height(root -> left);
    int rh = height(root -> right);
    
    return max(lh, rh) + 1;
}

int diameter(BinaryTreeNode<int>* root) {
  if(root == NULL) {
    return 0;
  }
  
  int a = height(root->left) + height(root->right);
  int b = diameter(root->left);
  int c = diameter(root->right);
  
  return max(a, max(b, c));
}
