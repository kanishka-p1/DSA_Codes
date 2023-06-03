/************************************************************************* QUESTION ******************************************************************************/

/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing 
its structure.

Example 1:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:
Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 
Constraints:
The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
*/

/***************************************************************************** ANSWER *****************************************************************************/

class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)) {
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        
        inorder(root);

        if(first && last) {
            swap(first->val, last->val);
        }
        else if(first && middle) {
            swap(first->val, middle->val);
        }
    }
};
