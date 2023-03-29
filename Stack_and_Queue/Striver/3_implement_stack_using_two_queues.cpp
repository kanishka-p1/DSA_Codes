/********************************************************************** QUESTION *************************************************************************************/

/*
Implement a Stack using two queues q1 and q2.

Example 1:
Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3 4
Explanation:
push(2) the stack will be {2}
push(3) the stack will be {2 3}
pop()   poped element will be 3 the 
        stack will be {2}
push(4) the stack will be {2 4}
pop()   poped element will be 4  
Example 2:
Input:
push(2)
pop()
pop()
push(3)
Output: 2 -1
Your Task:

Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as 
input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack(-1 if the stack is empty).

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= Number of queries <= 100
1 <= values of the stack <= 100
*/

/******************************************************************************** ANSWER ****************************************************************************/

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code      
        if(q1.size() == 0) {
            return -1;
        }
        int ans;
        while(q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        ans = q1.front();
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
}


// METHOD 2
class MyStack {
public:
queue<int> q1, q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
