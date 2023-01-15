/************************************************************************ PREORDER ***********************************************************************************/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return {};
        }

        ans.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};

// iterative approach

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return {};
        }
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right != NULL) {
                st.push(root->right);
            }
            if(root->left != NULL) {
                st.push(root->left);
            }
        }

        return ans;
    }
};

/************************************************************************** INORDER ***********************************************************************************/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);

        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }
};

// iterative approach

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty()) {
                    break;
                }
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};

/*************************************************************************** POSTORDER *******************************************************************************/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);

        left.insert(left.end(), right.begin(), right.end());
        left.push_back(root->val);

        return left;
    }
};

/*********************************************************************** LEVEL ORDER ********************************************************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};
