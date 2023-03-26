/*************************************************************************** QUESTION **********************************************************************************/

/*
Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list 
in the same way that we access the next element. His teacher explains doubly linked lists to him.
Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

Example 1:
Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
Example 2:
Input:
n = 1
arr = [1]
Output:
1
Explanation: Linked list for the given array will be 1.
Constraints:
1 <= n <= 105
1 <= arr[i] <= 100

Your Task:
You don't need to read input or print anything. Your task is to complete the function constructDLL() which takes arr[] as input parameters and 
returns the head of the Linked List.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/

/******************************************************************************** ANSWER ******************************************************************************/

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* root = new Node(arr[0]);
        Node* curr = root;
        curr->prev = NULL;
        for(int i = 1; i < arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            curr->next = temp;
            temp->prev = curr;
            curr = curr->next;
        }
        return root;
    }
};
