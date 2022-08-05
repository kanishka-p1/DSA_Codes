//                                                                      QUESTION

/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
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
ListNode* Solution::mergeKLists(vector<ListNode*> &lists) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(lists.size() == 0){
            return NULL;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != NULL){
                pq.push(head -> val);
                head = head -> next;
            }
        }
        
        ListNode* start = NULL;
        ListNode* end = NULL;

        while(!pq.empty()){
            if(start == NULL){
                start = new ListNode(pq.top());
                pq.pop();
                end = start;
            }
            else{
                end -> next = new ListNode(pq.top());
                pq.pop();
                end = end -> next;
            }
        }
        return start;
}
