//                                                                     QUESTION

/*
Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.
NOTE : You may assume 1 <= k <= Total number of nodes in BST
*/

//                                                                       ANSWER


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;
void helper(TreeNode* A, int& B) {
    if(!A) {
        return;
    }
    
    helper(A->left, B);
    
    if(--B == 0) {
        ans = A->val;
        return;
    }
    
    helper(A->right, B);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    helper(A, B);
    return ans;
}
