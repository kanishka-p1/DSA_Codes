/************************************************************************** QUESTION ***********************************************************************************/

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

/********************************************************************** RECURSION *************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

/*************************************************************************** QUEUE ***********************************************************************************/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int level = 0;
        if(root == NULL) {
            return level;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }

        return level;
    }
};

/********************************************************************* BALANCED BINARY TREE **************************************************************************/

/*
Given a binary tree, determine if it is height-balanced

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

/******************************************************************** ANSWER *****************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        if(abs(rh - lh) > 1) {
            return false;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) {
            return false;
        }

        return true;
    }
};

// approach 2 (time optimized)

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int lh = maxDepth(root->left);
        if(lh == -1) {
            return -1;
        }
        int rh = maxDepth(root->right);
        if(rh == -1) {
            return -1;
        }

        if(abs(lh - rh) > 1) {
            return -1;
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return maxDepth(root) != -1;
    }
};
