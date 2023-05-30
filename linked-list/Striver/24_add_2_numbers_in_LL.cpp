/************************************************************************* QUESTION *******************************************************************************/

/*
Employable by enrolling today! 

Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two 
numbers. For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215,
which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Example 1:
Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:
Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

/******************************************************************************* ANSWER *************************************************************************/

// TC = O(M + N)
// SC = O(MAX(M, N))

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int val) {
        Node* temp = new Node(val);
        // empty linked list
        if(head == NULL) {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0) {
            int val1 = 0;
            if(first != NULL) {
                val1 = first->data;
            }
            int val2 = 0;
            if(second != NULL) {
                val2 = second->data;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            // create node and add in ans linked list
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            if(first != NULL) {
                first = first->next;
            }
            if(second != NULL) {
                second = second->next;
            }
        }
        
        return ansHead;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // step 1 : reverse input linked list cause we have to add the digits from the back
        first = reverse(first);
        second = reverse(second);
        
        // step 2 : add the given 2 linked list
        Node* ans = add(first, second);
        
        // step 3 : reverse the ans
        ans = reverse(ans);
        
        return ans;
    }
};
