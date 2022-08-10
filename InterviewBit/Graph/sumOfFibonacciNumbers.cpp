//                                                                        QUESTION

/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?

Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 
*/


//                                                                          ANSWER

int Solution::fibsum(int A) {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    while(v.back() <= A) {
        int n = v.size();
        v.push_back(v[n - 2] + v[n - 1]);
    }
    v.pop_back();
    int ans = 0;
    while(A > 0) {
        int top = v.back();
        if(A - top < 0) {
            v.pop_back();
        }
        else {
            A = A - top;
            ans++;
        }
        if(A == 0) {
            return ans;
        }
    }
    return ans;
}
