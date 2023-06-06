/********************************************************************************* QUESTION ***************************************************************************/

/*
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:
Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:
Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 103
*/

/***************************************************************************** ANSWER *******************************************************************************/

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<int, vector<int>, greater<int>> pq;
           for(int i = 0; i < K; i++) {
               Node* temp = arr[i];
               while(temp != NULL) {
                   pq.push(temp->data);
                   temp = temp->next;
               }
           }
           Node* root = NULL;
           Node* head = NULL;
           while(!pq.empty()) {
               Node* temp = new Node(pq.top());
               if(root == NULL) {
                   root = temp;
                   head = temp;
               }
               head -> next = temp;
               head = head -> next;
               pq.pop();
           }
           return root;
    }
};


// APPROACH 2

class compare {
    public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        int k = lists.size();
        if(k == 0) {
            return NULL;
        }

        for(int i = 0; i < k; i++) {
            if(lists[i] != NULL) {
                minheap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minheap.size() > 0) {
            ListNode* top = minheap.top();
            minheap.pop();

            if(top->next) {
                minheap.push(top->next);
            }

            if(head == NULL) {
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = top;
            }
        }

        return head;

    }
};
