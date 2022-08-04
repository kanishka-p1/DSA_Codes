//                                                                      QUESTION


/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

*/


//                                                                          ANSWER

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n == 0) {
        return NULL;
    }
    if(n == 1) {
        return new TreeNode(A[0]);
    }
    
    int mid = n / 2;
    TreeNode* root = new TreeNode(A[mid]);
    
    vector<int> leftin(A.begin(), A.begin() + mid);
    vector<int> rightin(A.begin() + mid + 1, A.end());
    
    root->left = sortedArrayToBST(leftin);
    root->right = sortedArrayToBST(rightin);
    
    return root;
}
