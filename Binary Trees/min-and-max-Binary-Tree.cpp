#include<climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    
    pair<int, int> leftAns = getMinAndMax(root -> left);
    pair<int, int> rightAns = getMinAndMax(root -> right);
    
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;
    
    int fmax = max(max(lmax, rmax), root -> data);
    int fmin = min(min(lmin, rmin), root -> data);
    
    pair<int, int> p;
    p.first = fmin;
    p.second = fmax;
    
    return p;
}
