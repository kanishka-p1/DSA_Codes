#include <iostream>
#include "treenode.h"
using namespace std;

TreeNode<int> *takeInput()
{
    int rootdata;
    cout << "enter data : ";
    cin >> rootdata;
    cout << endl;
    TreeNode<int> *root = new TreeNode<int>(rootdata);

    int n;
    cout << "enter the num of children : ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
}