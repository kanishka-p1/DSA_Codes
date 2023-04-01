/************************************************************************ QUESTION ************************************************************************************/

/*
You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Example 1:
Input:
push(2)
push(3)
pop()
getMin()
push(1)
getMin()
Output: 2 1
Explanation: In the first test case for
query 
push(2)  Insert 2 into the stack.
         The stack will be {2}
push(3)  Insert 3 into the stack.
         The stack will be {2 3}
pop()    Remove top element from stack 
         Poped element will be 3 the
         stack will be {2}
getMin() Return the minimum element
         min element will be 2 
push(1)  Insert 1 into the stack.
         The stack will be {2 1}
getMin() Return the minimum element
         min element will be 1
Your Task:
You are required to complete the three methods push() which take one argument an integer 'x' to be pushed into the stack, pop() which returns a integer poped 
out from the stack and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Expected Time Complexity : O(1) for all the 3 methods.
Expected Auixilliary Space : O(1) for all the 3 methods.

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/

/**************************************************************************** ANSWER ********************************************************************************/

/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int mini = INT_MAX;;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()) {
               return -1;
           }
           return mini;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()) {
               return -1;
           }
           int curr = s.top();
           s.pop();
           if(curr > mini) {
               return curr;
           }
           else {
               int prevmin = mini;
               int val = 2* mini - curr;
               mini = val;
               return prevmin;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()) {
               s.push(x);
               mini = x;
           }
           else {
               if(x < mini) {
                   int val = 2*x - mini;
                   s.push(val);
                   mini = x;
               }
               else {
                   s.push(x);
               }
           }
           
       }
};
