/***************************************************************** MORRIS TRAVERSAL FOR INORDER *******************************************************************/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};

/**************************************************************** MORRIS TRAVERSAL FOR PREORDER *****************************************************************/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> postorder;
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                postorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = curr;
                    postorder.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return postorder;
    }
};
