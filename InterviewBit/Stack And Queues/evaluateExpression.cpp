//                                                                    QUESTION

/*
An arithmetic expression is given by a charater array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each character may be an integer or an operator.



Problem Constraints
1 <= N <= 105



Input Format
The only argument given is character array A.



Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.



Example Input
Input 1:
    A =   ["2", "1", "+", "3", ""]
Input 2:
    A = ["4", "13", "5", "/", "+"]


Example Output
Output 1:
    9
Output 2:
    6


Example Explanation*
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    13 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
    */


//                                                                            ANSWER

int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    unordered_map<string, int> mp;
    mp["+"] = 1;
    mp["-"] = 2;
    mp["*"] = 3;
    mp["/"] = 4;
    for(auto i = 0; i < A.size(); ++i)
    {
        //if(mp[A[i]] == 1 || mp[A[i]] == 2 || mp[A[i]] == 3 || mp[A[i]] == 4)
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
           if(!s.empty())
           {
               int b = s.top(); 
               s.pop();
               int a = s.top(); 
               s.pop();
               switch(mp[A[i]])  //A[i][0] returns a char since [i][0] gives first char.
               {                         
                   case 1: s.push(a + b); 
                            break;
                   case 2: s.push(a - b);
                            break;
                   case 3: s.push(a * b);
                            break;
                   case 4: 
                    if(b==0)
                        return 0;
                    s.push(a/b);
                    break;
                   default: break;
               }
           }
        }
        else
            //s.push(atoi(A[i].c_str())); //string to char to int method.
            s.push(stoi(A[i], nullptr, 10)); 
    }
    
    return s.top();
}
