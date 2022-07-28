//                                                                      QUESTION

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.
 */


//                                                                             ANSWER


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> v;
    vector<int> res;
    queue<TreeNode*> q;
    
    if(A == NULL) {
        return v;        
    }
    
    res.push_back(A->val);
    q.push(A);
    v.push_back(res);
    
    while(q.empty()!=true){
        vector<int> temp;
        int count = q.size();
        
        while(count){
            
            if(q.front()->left){
                q.push(q.front()->left);
                temp.push_back(q.front()->left->val);
            }
            
            
            if(q.front()->right){
                q.push(q.front()->right);
                temp.push_back(q.front()->right->val);
            }
        
            q.pop();
            count--;
        }
        
        if(!temp.empty())
            v.push_back(temp);
        
    }
    
    return v;
}
