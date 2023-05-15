/****************************************************************************** QUESTION ***************************************************************************/

/*
Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.

Example 1:
Input:
     10
    /
  10 
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:
Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSumProperty() that takes the root Node of the Binary Tree as input and 
returns 1 if all the nodes in the tree satisfy the following properties. Else, it returns 0. For every node, data value must be equal to the sum of data values 
in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Expected Time Complexiy: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 105
1 <= Data on nodes <= 105
*/

/********************************************************************************* ANSWER ***********************************************************************/
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

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if(root == NULL) {
         return 1;
     }
     if(!root->left && !root->right) {
         return 1;
     }
     int sum = 0;
     if(root->left) {
         sum += root->left->data;
     }
     if(root->right) {
         sum += root->right->data;
     }
     if(root->data != sum) {
         return 0;
     }
     return (isSumProperty(root->left) == 1) && (isSumProperty(root->right) == 1) ? 1 : 0;
    }
};
