/************************************************************************** QUESTION ***********************************************************************************/

/*
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:
5 10 39 1

        1
     /     \
   10     39
  /
5


Example 1:
Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19
Example 2:
Input:
          11
         /
       15
      /
     7
Output: 7 15 11

Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing 
the postorder traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 106
*/

/********************************************************************************* ANSWER ****************************************************************************/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
  if(root == NULL) {
      return {};
  }
  vector<int> ans = postOrder(root->left);
  vector<int> right = postOrder(root->right);
  ans.insert(ans.end(), right.begin(), right.end());
  ans.push_back(root->data);
  
  return ans;
}

// ITERATIVE USING 2 STACKS

vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> postOrder;
  if(root == NULL) {
      return {};
  }
  stack<Node*> st1;
  stack<Node*> st2;
  st1.push(root);
  
  while(!st1.empty()) {
      Node* node = st1.top();
      st1.pop();
      st2.push(node);
      if(node->left) {
          st1.push(node->left);
      }
      if(node->right) {
          st1.push(node->right);
      }
  }
  
  while(!st2.empty()) {
      postOrder.push_back(st2.top()->data);
      st2.pop();
  }
  
  return postOrder;
}

// ITERATIVE USING 1 STACK

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* temp;
        stack<TreeNode*> st;
        vector<int> ans;
        if(root == NULL) {
            return {};
        }

        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                temp = st.top()->right;
                if(temp == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return ans;
    }
};
