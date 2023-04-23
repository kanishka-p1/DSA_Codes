/******************************************************************************** QUESTION *****************************************************************************/

/*
Given a binary tree, find its preorder traversal.

Example 1:
Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 
Example 2:
Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 104
0 <= Data of a node <= 105
*/

/******************************************************************************* ANSWER *******************************************************************************/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  if(root == NULL) {
      return {};
  }
  
  ans.push_back(root->data);
  vector<int> left = preorder(root->left);
  ans.insert(ans.end(), left.begin(), left.end());
  vector<int> right = preorder(root->right);
  ans.insert(ans.end(), right.begin(), right.end());
  
  return ans;
}

// ITERATIVE

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
