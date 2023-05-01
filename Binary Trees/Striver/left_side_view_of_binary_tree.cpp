/************************************************************************** QUESTION ***********************************************************************************/

/*
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the 
function leftView(), which accepts root of the tree as argument.
Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:
Input:
   1
 /  \
3    2
Output: 1 3

Example 2:
Input:
Output: 10 20 40
Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the 
driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

/******************************************************************************** ANSWER ****************************************************************************/

void helper(Node* root, vector<int>& ans, int level) {
    if(root == NULL) {
        return;
    }
    if(ans.size() == level) {
        ans.push_back(root->data);
    }
    helper(root->left, ans, level+1);
    helper(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   helper(root, ans, 0);
   return ans;
}
