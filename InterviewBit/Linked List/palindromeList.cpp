//                                                                      QUESTION

/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
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
int Solution::lPalin(ListNode* A) {
    stack<int> st;
    ListNode* temp = A;
    
    while(temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }
    
    while(A != NULL) {
        if(st.top() != A->val) {
            return false;
        }
        st.pop();
        A = A->next;
    }
    
    return true;
}
