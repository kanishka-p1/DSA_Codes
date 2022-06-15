#include <iostream>
#include "binary-tree.h"
#include <queue>
using namespace std;

BinaryTreeNode<int>* takeinput() {
  int rootdata;
  cout << "enter root data : " << endl;
  cin >> rootdata;
  if(rootdata == -1) {
    return NULL;
  }
  
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
  
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  
  while(pendingNodes.size() != 0) {
    BinaryTreeNode<int>* fr = pendingNodes.front();
    pendingNodes.pop();
    
    cout << "enter the left child of" << front->data << endl;
    int leftChild;
    cin << leftChild;
    if(leftChild != -1) {
      BinaryTreeNode<int>* lchild = new  BinaryTreeNode<int>*(leftChild);
      front->left = lchild;
      pendingNodes.push(lchild);
    }
    
    cout << "enter the right child of" << front->data << endl;
    int rightChild;
    cin << rightChild;
    if(rightChild != -1) {
      BinaryTreeNode<int>* rchild = new  BinaryTreeNode<int>*(rightChild);
      front->right = rchild;
      pendingNodes.push(rchild);
    } 
  }
  return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
    queue <BinaryTreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int> * f = q.front();
        q.pop();
        
        cout << root->data << ":";
        
        if(root->left != NULL){
            cout << "L :" << root->left->data << ",";
            q.push(root->left);
        }
        else{
            cout << "L: -1,";
        }
        
        if(root->right != NULL){
            cout << "R :" << root->right->data;
            q.push(root->right);
        }
        else{
            cout << "R: -1";
        }
        cout << endl;
        root = q.front();
    }
}

int main() {
  BinaryTreeNode<int>* root = takeinput();
  printLevelWise(root);
  delete root;
  return;
}
