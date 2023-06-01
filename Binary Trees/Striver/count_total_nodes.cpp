/************************************************************************* QUESTION ********************************************************************************/

/*
Given the root of a complete binary tree, return the number of the nodes in the tree. According to Wikipedia, every level, except possibly the last, is completely 
filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:
Input: root = []
Output: 0
Example 3:
Input: root = [1]
Output: 1
 
Constraints:
The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
*/

/**************************************************************************** ANSWER *******************************************************************************/

// APPROACH 1
class Solution {
public:
    int countNodes(TreeNode* root) {
        return root == NULL ? 0 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// APPROACH 2
class Solution {
public:
    void inorder(TreeNode* root, int& count) {
        if(root) {
            count++;
        }
        if(root->left) {
            inorder(root->left, count);
        }
        if(root->right) {
            inorder(root->right, count);
        }
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int count = 0;
        inorder(root, count);

        return count;
    }
};

// APPROACH 3
class Solution {
public:
    int findlh(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int findrh(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = findlh(root);
        int rh = findrh(root);

        if(lh == rh) {
            return (1<<lh) - 1; // pow(2, h) -1
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
