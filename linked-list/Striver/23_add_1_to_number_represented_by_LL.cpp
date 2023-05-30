/************************************************************************* QUESTION ********************************************************************************/

/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:
Input:
LinkedList: 4->5->6
Output: 457 
Example 2:
Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. 
The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 1021
*/

/************************************************************************ ANSWER **********************************************************************************/

class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        bool flag = true;
        Node* curr = head;
        
        while(curr != NULL && flag == true) {
            if(curr->next == NULL && curr->data == 9) {
                curr->data = 1;
                Node* temp = new Node(0);
                temp->next = head;
                head = temp;
                curr = curr->next;
            }
            else if(curr->data == 9) {
                curr->data = 0;
                curr = curr->next;
            }
            else {
                curr->data = curr->data + 1;
                curr = curr->next;
                flag = false;
            }
        }
        
        head = reverse(head);
        return head;
    }
};
