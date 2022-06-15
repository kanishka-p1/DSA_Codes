#include <iostream>
#include "binary-tree.h"
using namespace std;

BinaryTreeNode<int>* takeinput() {
  int rootdata;
  cout << "enter data : " << endl;
  cin >> rootdata;
  if(rootdata == -1) {
    return NULL;
  }
  
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
  BinaryTreeNode<int>* leftChild = takeinput();
  BinaryTreeNode<int>* rightChild = takeinput();
  
  root->left = leftChild;
  root->right = rightChild;
  return root;
}
  
 
printTree(BinaryTreeNode<int>* root) {
  if(root == NULL) {
    return;
  }
  
  cout << root->data << ":";
  if(root->left != NULL) {
    cout << "Left : " << root->left->data;
  }
  if(root->right != NULL) {
    cout << "Right : " << root->right->data;
  }
  
  cout << endl;
  printTree(root->left);
  printTree(root->right);
}  

int main() {
  BinaryTreeNode<int>* root = takeinput();
  printTree(root);
  return;
}
