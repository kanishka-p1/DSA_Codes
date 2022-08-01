//                                                                        QUESTION


/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/


//                                                                         ANSWER

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A == NULL || A->next == NULL || B == 0) {
        return A;
    }
    
    ListNode* temp = A;
    int count = 1;
    
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    
    temp->next = A;
    B = B % count;
    
    while(--count >= B) {
        temp = temp->next;
    }
    
    ListNode* ans = temp->next;
    temp->next = NULL;
    
    return ans;
}
