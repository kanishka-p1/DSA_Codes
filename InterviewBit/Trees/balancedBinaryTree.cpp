/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    
    return 1 + max(height(root->left), height(root->right));
}

int Solution::isBalanced(TreeNode* A) {
    if(A == NULL) {
        return true;
    }
    
    int lh = height(A->left);
    int rh = height(A->right);
    
    if(lh - rh > 1 && rh - lh > 1) {
        return false;
    }
    if(abs(lh - rh) <= 1 && isBalanced(A->left) && isBalanced(A->right)) {
        return true;
    }
    
    return false;
}
