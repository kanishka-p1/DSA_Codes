//                                                                        QUESTION

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.
*?


//                                                                        ANSWER


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || !A->next) {
        return A;
    }
    
    ListNode* curr = A;
    
    while(curr) {
        while(curr->next && curr->val == curr->next->val) {
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
    
    return A;
}
