/************************************************************************ QUESTION ************************************************************************************/

/*
Given an integer i. Print the maximum number of nodes on level i of a binary tree.
Example 1:
Input: 5
Output: 16
Example 2:
Input: 1
Output: 1
 
Your Task:
Complete the function countNode() which takes an integer i as input and prints the count of maximum number of nodes at that level.

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)

Constraints:
1<=i<=20
*/

/**************************************************************************** ANSWER **********************************************************************************/

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        int ans = pow(2, i - 1);
        return ans;
    }
};
