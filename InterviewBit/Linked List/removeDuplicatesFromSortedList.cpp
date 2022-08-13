//                                                                    QUESTION


/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/


//                                                                      ANSWER


ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL || A->next == NULL) {
        return A;
    }
    
    ListNode* head = new ListNode(0);
    head->next = A;
    ListNode* prev = head;
    while (A)
    {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next; 
        else 
            prev->next = A->next;
            
        A = A->next;
    }
    return head->next;
}
