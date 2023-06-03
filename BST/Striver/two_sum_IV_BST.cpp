/*********************************************************************** QUESTION *********************************************************************************/

/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/

/**************************************************************************** ANSWER *****************************************************************************/

// APPROACH 1 USING INORDER

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {  
        if(root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inor;
        inorder(root, inor);

        int i = 0, j = inor.size()-1;
        while(i < j) {
            if(inor[i] + inor[j] == k) {
                return true;
            }
            if(inor[i] + inor[j] < k) {
                i++;
            }
            else if(inor[i] + inor[j] > k) {
                j--;
            }
        }

        return false;
    }
};

//  APPROACH 2 USING BST ITERATOR

class BSTiterator {
    stack<TreeNode*> st;
    // reverse = true -> before
    // reverse = false -> next
    bool reverse = true;

    void pushAll(TreeNode* root) {
        while(root) {
            st.push(root);
            if(reverse) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }

    public:
    BSTiterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) {
            pushAll(temp->right);
        }
        else {
            pushAll(temp->left);
        }
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) {
            return false;
        }
        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j) {
            if(i + j == k) {
                return true;
            }
            else if(i + j < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }

        return false;
    }
};
