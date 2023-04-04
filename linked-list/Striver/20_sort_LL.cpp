/***************************************************************************** QUESTION ******************************************************************************/

/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/

/******************************************************************************* ANSWER ******************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* midp_ll(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    ListNode* mergetll(ListNode* head1, ListNode* head2){
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        
        if(head1 -> val < head2 -> val){
            head1 -> next = mergetll(head1 -> next, head2);
            return head1;
        }
        else{
            head2 -> next = mergetll(head1, head2 -> next);
            return head2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* mid = midp_ll(head);
        ListNode* midf = mid -> next;
        mid -> next = NULL;
        ListNode* start = sortList(head);
        ListNode* center = sortList(midf);
        ListNode* nhead = mergetll(start, center);
        return nhead;
    }
};
