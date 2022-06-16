vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
  if(root == NULL) {
    return NULL;
  }
  
  if(root->data == data) {
    vector<int>* ans = new vector<int>();
    ans.push_back(root->data);
    return ans;
  }
  
  vector<int>* leftans = getRootToNodePath(root->left, data);
  if(leftans != NULL) {
    leftans.push_back(root->data);
    return leftans;
  }
  
  vector<int>* rightans = getRootToNodePath(root->right, data);
  if(rightans != NULL) {
    rightans.push_back(root->data);
    return rightans;
  }
  else {
    return NULL;
  }
}
