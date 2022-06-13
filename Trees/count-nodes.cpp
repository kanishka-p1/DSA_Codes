int countNodes(TreeNode<int>* root) {
  if(root == NULL) {
    return 0;
  }
  
  int res = 1;
  for(int i = 0; i < root->children.size(); i++) {
    res += countNodes(root->children[i]);
  }
  return res;
}  
