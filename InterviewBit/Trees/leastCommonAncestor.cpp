//                                                                        QUESTION

/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
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
 
bool find(TreeNode* root, int x) {
    if(root == NULL) {
        return false;
    }
    if(root->val == x) {
        return true;
    }
    
    if(find(root->left, x) || find(root->right, x)) {
        return true;
    }
    return false;
}
 
TreeNode* LCA(TreeNode* A, int B, int C) {
    if(A == NULL) {
       return NULL;
    }
    if(A->val == B || A->val == C) {
        return A;
    }
    
    TreeNode* left = LCA(A->left, B, C);
    TreeNode* right = LCA(A->right, B, C);
    
    if(left && right) {
        return A;
    }
    else if(right == NULL) {
        return left;
    }
    else {
        return right;
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    bool y = find(A, B);
    bool z = find(A ,C);
    
    if(y && z) {
        TreeNode* ans = LCA(A, B, C);
        return ans->val;
    }
    else {
        return -1;
    }
}
