/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    // Define the data members
  BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
      root == NULL;
    }
  
  ~BST() {
    delete root;
  }
  
	/*----------------- Public Functions of BST -----------------*/

  private:
  void print(BinaryTreeNode<int>* root) {
    if(root == NULL) {
      return;
    }
    cout << root->data << ":";
    
    if(root->left != NULL) {
      cout << "L:" << root->left->data << ",";
    }
    
    if(root->right != NULL) {
      cout << "R:" << root->right->data;
    }
    
    cout << endl;
    print(root->left);
    print(root->right);
  }
  
  public:
    void remove(int data) { 
        // Implement the remove() function 
      root = remove(root, data);
    }

    void print() { 
        // Implement the print() function
      return print(root);
    }

  private:
  BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) {
      BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
      return newNode;
    }
    
    if(data <= root->data) {
      root->left = insert(root->left, data);
    }
    else {
      root->right = insert(root->right, data);
    }
    return root;
  }
  
  public:
    void insert(int data) { 
        // Implement the insert() function 
      this->root = insert(this->root, data);
    }

  private: 
    bool search(BinaryTreeNode<int>* root, int data) {
      if(root == NULL) {
        return false;
      }
      
      if(data == root->data) {
        return true;
      }
      else if(data < root->data) {
        return search(root->left, data);
      }
      else {
        return search(root->right, data);
      }
    }
  
  public:
    bool search(int data) {
		// Implement the search() function 
      return search(root, data);
    }
};
