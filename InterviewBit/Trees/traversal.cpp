//INORDER

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    if(A == NULL) {
        return ans;
    }
    
    vector<int> l = inorderTraversal(A->left);
    ans = l;
    
    ans.push_back(A->val);
    
    vector<int> r = inorderTraversal(A->right);
    ans.insert(ans.end(), r.begin(), r.end());
    
    return ans;
}


//PREORDER

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    if(A == NULL) {
        return ans;
    }
    
    ans.push_back(A->val);
    
    vector<int> l = preorderTraversal(A->left);
    ans.insert(ans.end(), l.begin(), l.end());
    
    vector<int> r = preorderTraversal(A->right);
    ans.insert(ans.end(), r.begin(), r.end());
    
    return ans;
}

//POSTORDER

vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ans;
    
    if(A == NULL) {
        return ans;
    }
    
    vector<int> l = postorderTraversal(A->left);
    ans.insert(ans.end(), l.begin(), l.end());
    
    vector<int> r = postorderTraversal(A->right);
    ans.insert(ans.end(), r.begin(), r.end());
    
    ans.push_back(A->val);
    
    return ans;
}
