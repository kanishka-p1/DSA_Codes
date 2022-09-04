//                                                                        QUESTION

/*
Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE: 

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7


Input Format
First argument is an integer A.

Second argument is an integer array B of size N.



Output Format
Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.



Example Input
Input 1:

 A = 3
 B = [6, 5]
Input 2:

 A = 5
 b = [2, 4, 6, 8, 10]


Example Output
Output 1:

 14
Output 2:

 33


Example Explanation
Explanation 1:

 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
 so, total number of chocolates eaten are 6 + 5 + 3 = 14
 */


//                                                                            ANSWER

int check(priority_queue<int>& q, int& a) {
    int ans = 0, mod = pow(10, 9) + 7;
    
    while(a) {
        int top = q.top();
        ans = (ans + (top % mod)) % mod;
        q.pop();
        q.push(top/2);
        a--;
    }
    
    return ans;
}

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> q;
    if(B.size() == 0) {
        return 0;
    }
    
    for(int i = 0; i < B.size(); i++) {
        q.push(B[i]);
    }
    
    return check(q, A);
}
