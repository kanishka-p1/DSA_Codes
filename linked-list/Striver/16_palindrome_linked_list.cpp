/*********************************************************************** QUESTION ************************************************************************************/

/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false
 
Constraints:
The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

/************************************************************************** ANSWER ***********************************************************************************/

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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* nxt = NULL;

        while(head != NULL) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }


    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;

        while(slow != NULL) {
            if(head->val != slow->val) {
                return false;
            }
            head = head->next;
            slow = slow->next;
        }

        return true;



    //     ListNode *slow = head, *fast = head, *prev = nullptr, *temp;

    //     while(fast && fast->next) {
    //         fast = fast->next->next;
    //         temp = slow->next;
    //         slow->next = prev;
    //         prev = slow;
    //         slow = temp;
    //     }
    //     if(fast) {
    //         slow = slow->next;
    //     }
    //     while(slow) {
    //         if(slow->val != prev->val) {
    //             return false;
    //         }
    //         else {
    //             slow = slow->next;
    //             prev = prev->next;
    //         }
    //     }
    // return true;



        // stack<int> st;
        // ListNode* temp = head;
        
        // while(temp != NULL) {
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        
        
        // while(head != NULL) {
        //     if(st.top() != head->val) {
        //         return false;
        //     }
        //     st.pop();
        //     head = head->next;
        // }
        
        // return true;
    }
};
