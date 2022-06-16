BinaryTreeNode<int> *tree(int *input, int start, int end){
    if(start > end){
        return NULL;
    }
    
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int> (input[mid]);
    root -> left = tree(input, start, mid - 1);
    root -> right = tree(input, mid + 1, end);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    int start = 0;
    int end = n-1;
    tree(input, start, end);
}
