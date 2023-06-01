/*********************************************************************** QUESTION ********************************************************************************/

/*
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

Example 1:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Your Task:  
You don't need to read input or print anything. Complete the function minTime() which takes the root of the tree and target as input parameters and returns the 
minimum time required to burn the complete binary tree if the target is set on fire at the 0th second.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 104
*/

/******************************************************************************** ANSWER ***********************************************************************/

class Solution {
  public:
    int findDistance(map<Node*, Node*>& mp, Node* target) {
        queue<Node*> q;
        q.push(target);
        map<Node*, bool> visited;
        visited[target] = true;
        int maxi = 0;
        
        while(!q.empty()) {
            int size = q.size();
            int flag = 0;
            for(int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    flag = 1;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    flag = 1;
                }
                if(mp[node] && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                    flag = 1;
                }
            }
            if(flag == 1) {
                maxi++;
            }
        }
        
        return maxi;
    }
  
    Node* markParent(Node* root, map<Node*, Node*>& mp, int target) {
        queue<Node*> q;
        q.push(root);
        Node* res;
        while(!q.empty()) {
            Node* node = q.front();
            if(node->data == target) {
                res = node;
            }
            q.pop();
            if(node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        
        return res;
    }
  
    int minTime(Node* root, int targ) 
    {
        // Your code goes here
        map<Node*, Node*> mp;
        Node* target = markParent(root, mp, targ);
        int maxi = findDistance(mp, target);
        return maxi;
    }
};
