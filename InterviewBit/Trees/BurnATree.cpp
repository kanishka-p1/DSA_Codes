//                                                                       QUESTION

/*
Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. 
 Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.

Problem Constraints
2 <= number of nodes <= 105

1 <= node value, B <= 105

node value will be distinct



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B denoting the node value of leaf node.



Output Format
Return an integer denoting the minimum time required to burn the complete binary tree.



Example Input
Input 1:

 Tree :      1 
            / \ 
           2   3 
          /   / \
         4   5   6
 B = 4
Input 2:

 Tree :      1
            / \
           2   3
          /     \
         4       5 
 B = 5 


Example Output
Output 1:

 4
Output 2:

 4


Example Explanation
Explanation 1:

 After 1 sec: Node 4 and 2 will be burnt. 
 After 2 sec: Node 4, 2, 1 will be burnt.
 After 3 sec: Node 4, 2, 1, 3 will be burnt.
 After 4 sec: Node 4, 2, 1, 3, 5, 6(whole tree) will be burnt.
 
Explanation 2:

 After 1 sec: Node 5 and 3 will be burnt. 
 After 2 sec: Node 5, 3, 1 will be burnt.
 After 3 sec: Node 5, 3, 1, 2 will be burnt.
 After 4 sec: Node 5, 3, 1, 2, 4(whole tree) will be burnt.
 */

//                                                                      ANSWER

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /*
 INFO
 ldepth = maximum height of left subtree
 rdepth = maximum height of right subtree
 contains - stores true if tree rooted at current node contains the first burnt node
 time - time to reach fire from the initally burnt leaf node to this node
 */
 
struct Info {
    int lDepth;
    int rDepth;
    bool contains;
    int time;
    Info()
    {
        lDepth = rDepth = 0;
        contains = false;

        time = -1;
    }
};

/*
    Function to calculate time required to burn tree completely
    node - address of current node
    info - extra information about current node
    target - node that is fired
    res - stores the result
*/

void calcTime(TreeNode* node, Info& info, int target, int& res){
    // Base case: if root is null
    if (node == NULL) {
        return;
    }

    // If current node is leaf
    if (node->left == NULL && node->right == NULL) {

        // If current node is the first burnt node
        if (node->val == target) {
            info.contains = true;
            info.time = 0;
        }
        return;
    }

    // Information about left child of root
    Info leftInfo;
    calcTime(node->left, leftInfo, target, res);

    // Information about right child of root
    Info rightInfo;
    calcTime(node->right, rightInfo, target, res);

    // If left subtree contains the fired node then time required to reach fire to current node will be (1 + time required for left child)
    info.time = (node->left && leftInfo.contains) ? (leftInfo.time + 1) : -1;

    // If right subtree contains the fired node then time required to reach fire to current node will be (1 + time required for right child)
    if (info.time == -1)
        info.time = (node->right && rightInfo.contains) ? (rightInfo.time + 1) : -1;

    // Storing(true or false) if the tree rooted at current node contains the fired node
    info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));

    // Calculate the maximum depth of left subtree
    info.lDepth = !(node->left) ? 0 : (1 + max(leftInfo.lDepth, leftInfo.rDepth));

    // Calculate the maximum depth of right subtree
    info.rDepth = !(node->right) ? 0 : (1 + max(rightInfo.lDepth, rightInfo.rDepth));

    // Calculating answer
    if (info.contains) {
        // If left subtree exists and it contains the fired node
        if (node->left && leftInfo.contains) {
            // calculate result
            res = max(res, info.time + info.rDepth);
        }

        // If right subtree exists and it contains the fired node
        if (node->right && rightInfo.contains) {
            // calculate result
            res = max(res, info.time + info.lDepth);
        }
    }
}
 
int Solution::solve(TreeNode* A, int B) {
    int res = 0;
    Info info;
    calcTime(A, info, B, res);
    return res;
}
