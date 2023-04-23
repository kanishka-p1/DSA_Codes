/*************************************************************************** QUESTION *********************************************************************************/

/*
Complete the function to find spiral order traversal of a tree. For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

Example 1:
Input:
      1
    /   \
   3     2
Output:1 3 2
Example 2:
Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. 
The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

/***************************************************************************** ANSWER *********************************************************************************/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL) {
        return {};
    }
    queue<Node*> q;
    q.push(root);
    bool flag = false;
    
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) {
                q.push(node->left);
            }
            if(node->right != NULL) {
                q.push(node->right);
            }
            level.push_back(node->data);
        }
        if(!flag) {
            reverse(level.begin(), level.end());
            flag = true;
        }
        else {
            flag = false;
        }
        for(auto it : level) {
            ans.push_back(it);
        }
    }
    return ans;
}
