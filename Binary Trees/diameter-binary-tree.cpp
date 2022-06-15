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

             *************************************************************************************************************************************
            
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
  if(root == NULL) {
      pair<int, int> p;
      p.first = 0;
      p.second = 0;
      return p;
  }
                 
  pair<int, int> lans = heightDiameter(root->left);
  pair<int, int> rans = heightDiameter(root->right);                  
  int lh = lans.first;
  int ld = lans.second;
  int rh = rans.first;
  int rd = rans.second;
  int hans = 1 + max(lh, rh);
  int dans = max(lh + rh, max(ld, rd));
                 
  pair<int, int> ans;
  p.first = hans;
  p.second = dans;
                 
  return p;
}
