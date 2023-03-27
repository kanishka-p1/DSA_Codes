/*************************************************************************** QUESTION *********************************************************************************/

/*
Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Example 2:

Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9  
x = 1
Output: 5 2 9
Your Task:
The task is to complete the function deleteNode() which should delete the node at given position and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
2 <= size of the linked list <= 1000
1 <= x <= N
*/

/****************************************************************************** ANSWER *******************************************************************************/

// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
      int pos = 1;
      Node* temp = head_ref;
      Node* ref = temp;
      
      if(x == 1) {
          temp = temp -> next;
          temp -> prev = NULL;
          return temp;
      }
      
      while(pos < x) {
          temp = temp -> next;
          pos++;
      }
      
      ref = temp -> prev;
      ref -> next = temp -> next;
      temp -> next = NULL;
      return head_ref;
    }
};
