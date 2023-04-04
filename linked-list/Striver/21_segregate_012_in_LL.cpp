/*********************************************************************** QUESTION **************************************************************************************/

/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros 
segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:
Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:
Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the 
modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
*/

/****************************************************************************** ANSWER *******************************************************************************/

// WITH THE USE OF DATA REPLACEMENT 

// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zero = 0;
        int one = 0;
        int two = 0;
        
        Node* temp = head;
        
        while(temp) {
            if(temp->data == 0) {
                zero++;
            } 
            else if(temp->data == 1) {
                one++;
            }
            else if(temp->data == 2) {
                two++;
            }
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp) {
            while(zero != 0) {
                temp->data = 0;
                temp = temp->next;
                zero--;
            }
            while(one != 0) {
                temp->data = 1;
                temp = temp->next;
                one--;
            }
            while(two != 0) {
                temp->data = 2;
                temp = temp->next;
                two--;
            }
        }
        return head;
    }
};

// WITHOUT DATA REPLACEMENT


