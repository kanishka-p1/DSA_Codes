//                                                                        QUESTION

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


//                                                                        ANSWER

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL || A->next == NULL) {
        return A;
    }
    ListNode* temp = A;
    temp = A->next;
    A->next = swapPairs(A->next->next);
    temp->next = A;
    
    return temp;
}
