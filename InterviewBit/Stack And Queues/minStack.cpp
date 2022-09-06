//                                                                          QUESTION

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
*/


//                                                                             ANSWER

stack<int> s1, s2;

MinStack::MinStack() {
    while(!s1.empty()) {
        s1.pop();
    }
    while(!s2.empty()) {
        s2.pop();
    }
}

void MinStack::push(int x) {
    s1.push(x);
    if(s2.empty() || x <= s2.top()) {
        s2.push(x);
    }
}

void MinStack::pop() {
    int x;
    if(!s1.empty()) {
        x = s1.top();
        s1.pop();
    }
    if(!s2.empty() && s2.top() == x) {
        s2.pop();
    }
}

int MinStack::top() {
    if(s1.empty()) {
        return -1;
    }
    return s1.top();
}

int MinStack::getMin() {
    if(s2.empty()) {
        return -1;
    }
    return s2.top();
}
