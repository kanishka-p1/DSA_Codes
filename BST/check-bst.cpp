#include<climits>

//
bool helper(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL){
        return true;
    }
    
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool left = helper(root -> left, min, root -> data - 1);
    bool right = helper(root -> right, root -> data, max);
    
    return left && right;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    int min = INT_MIN;
    int max = INT_MAX;
    return helper(root, min, max);
}

//
int maximum(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MIN;
    }
    
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return INT_MAX;
    }
    
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        return true;
    }
    
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool ans = (root->data > leftmax) && (root->data <= rightmin) && (isBST(root->left)) && (isBST(root->right));
    return ans;
}

//
class isBSTreturn {
    public:
      int maximum;
      int minimum;
      bool isBST;
};

isBSTreturn isBST2(BinaryTreeNode<int> *root) {
    if(root == NULL) {
        isBSTreturn ans;
        ans.isBST = true;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        
        return ans;
    }
    
    isBSTreturn leftans = isBST2(root->left);
    isBSTreturn rightans = isBST2(root->right);
    int fmin = min(root->data, min(leftans.minimum, rightans.minimum));
    int fmax = max(root->data, max(leftans.maximum, rightans.maximum));
    bool fans = (root->data > leftans.maximum) && (root->data <= right.minimum) && leftans.isBST && rightans.isBST;
    isBSTreturn ans;
    ans.isBST = fans;
    ans.minimum = fmin;
    ans.maximum = fmax;
    
    return ans;
}

//without helper but same as 1
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL) {
        return true;
    }
    
    if(root -> data < min || root -> data > max){
        return false;
    }
    
    bool left = isBST(root -> left, min, root -> data - 1);
    bool right = isBST(root -> right, root -> data, max);
    
    return left && right;
}
