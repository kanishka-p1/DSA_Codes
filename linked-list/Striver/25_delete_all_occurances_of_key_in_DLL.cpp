/************************************************************************* QUESTION ******************************************************************************/

/*
You are given the head of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key and return the new DLL.

Example:
Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. 
Delete all occurrences of the key from the given DLL.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
0<=Number of Nodes<=104
-103<=Node Value <=103
*/

/********************************************************************************* ANSWER *************************************************************************/
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* head = *head_ref;
        
        while(head != NULL) {
            if(head->data == x) {
                if(head == *head_ref) {
                    *head_ref = head->next;
                }
                Node* next = head->next;
                Node* prev = head->prev;
                
                if(prev != NULL) {
                    prev->next = next;
                }
                if(next != NULL) {
                    next->prev = prev;
                }
            }
            head = head->next;
        }
    }
};
