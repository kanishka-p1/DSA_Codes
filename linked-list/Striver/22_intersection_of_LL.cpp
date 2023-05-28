/*********************************************************************** QUESTION *******************************************************************************/

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, 
return null.
For example, the following two linked lists begin to intersect at node c1:
The test cases are generated such that there are no cycles anywhere in the entire linked structure.
Note that the linked lists must retain their original structure after the function returns.
Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):
intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the 
intersected node, then your solution will be accepted.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes 
before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. 
In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same 
location in memory.
Example 2:
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before 
the intersected node in B.
Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while 
skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 
Constraints:
The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
1 <= m, n <= 3 * 104
1 <= Node.val <= 105
0 <= skipA < m
0 <= skipB < n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.
*/

/******************************************************************************** ANSWER ************************************************************************/

// BRUTE 1 
// CHECKING EACH NODE OF 2ND LINKED LIST WITH EVERY NODE OF 1ST LINKED LIST

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(b != NULL) {
            while(a != NULL) {
                if(a == b) {
                    return a;
                }
                a = a->next;
            }
            a = headA;
            b = b->next;
        }

        return NULL;
    }
};

// BRUTE 2
// HASHING ALL NODES OF LINKED LIST 2 IN MAP THEN CHECKING FOR EVERY NODE OF LINKED LIST 1 WHICH ALREADY EXISTS IN THE MAP
// TC = O(N+M)
//SC = O(N)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode* a = headA;
        ListNode* b = headB;

        while(a) {
            mp[a]++;
            a = a->next;
        }

        while(b) {
            if(mp[b] == 1) {
                return b;
            }
            b = b->next;
        }

        return NULL;
    }
};

// OPTIMAL 1
// MAKING THE STARTING POINT OF BOTH LINKED LIST SAME AND COMPARING THEM 
// TC = O(M) + O(N) + O(M - N) ~~ O(2M)
// SC = O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int l1 = 0, l2 = 0;

        while(a) {
            l1++;
            a = a->next;
        }
        while(b) {
            l2++;
            b = b->next;
        }

        int diff = abs(l1-l2);

        a = headA;
        b = headB;

        for(int i = 0; i < diff; i++) {
            if(l1 > l2) {
                a = a->next;
            }
            else if(l1 < l2) {
                b = b->next;
            }
        }

        while(a && b) {
            if(a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }

        return NULL;
    }
};

// OPTIMAL 2
// TC = O(2M)
// SC = O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        if(a == NULL || b == NULL) {
            return NULL;
        }

        while(a != b) {
            a = a->next;
            b = b->next;

            if(a == b) {
                return a;
            }

            if(a == NULL) {
                a = headB;
            }
            if(b == NULL) {
                b = headA;
            }
        }

        return a;
    }
};
