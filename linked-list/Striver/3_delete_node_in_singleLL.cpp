/************************************************************************* QUESTION ***********************************************************************************/

/*
Given a singly linked list and an integer x.Delete xth node from the singly linked list.

Example 1:
Input: 1 -> 3 -> 4 
       x = 3
Output: 1 -> 3
Explanation:
After deleting the node at 3rd
position (1-base indexing), the
linked list is as 1 -> 3. 
Example 2:
Input: 1 -> 5 -> 2 -> 9 
x = 2
Output: 1 -> 2 -> 9
Explanation: 
After deleting the node at 2nd
position (1-based indexing), the
linked list is as 1 -> 2 -> 9.
 
Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. 
The function returns the head of the modified linked list.

Constraints:
1 <= T <= 300
2 <= N <= 100
1 <= x <= N
*/

/***************************************************************************** ANSWER *********************************************************************************/

/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node* curr = head;
    Node* prev = NULL;
    if(x == 1) {
        curr = curr -> next;
        return curr;
    }
    
    for(int i = 1; i <= x - 1; i++) {
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = curr -> next;
    curr -> next = NULL;
    
    return head;
}


// leetcode O(n) solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node->next != NULL) {
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
        }
        prev -> next = NULL;
    }
};

// leetcode O(1) solution
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
