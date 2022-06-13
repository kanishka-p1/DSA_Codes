/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
#include <queue>
void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue <TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()) {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ":";
        
        for(int i = 0; i < root->children.size(); i++) {
            pendingNodes.push(root -> children[i]);
            
            if(i != root -> children.size() - 1) {
                cout << root -> children[i] -> data <<",";
            }
            else {
                cout << root -> children[i] -> data;
            }
        }
        root = pendingNodes.front();
        cout << endl;
    }
}
