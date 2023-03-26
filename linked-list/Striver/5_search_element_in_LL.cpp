/*********************************************************************** QUESTION *************************************************************************************/

/*
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:
Input:
n = 4
1->2->3->4
Key = 3
Output:
True
Explanation:
3 is present in Linked List, so the function returns true.
Your Task:
Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value 
by checking the key is present or not in the linked list.

Constraint:
1 <= n <= 105
1 <= key <= 105

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

/*********************************************************************** ANSWER ************************************************************************************/

/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        Node* temp = head;
        while(temp -> next != NULL) {
            if(temp -> data == key) {
                return true;
            }
            temp = temp -> next;
        }
        return false;
    }
};
