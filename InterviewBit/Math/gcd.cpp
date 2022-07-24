//                                                                      QUESTION

/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.

Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
NOTE : DO NOT USE LIBRARY FUNCTIONS
*/

//                                                                          ANSWER

int Solution::gcd(int A, int B) {
    if(A == 0 && B == 0) {
        return 0;
    }
    if(A == 0 && B != 0) {
        return B;
    }
    if(A != 0 && B == 0) {
        return A;
    }
    
    int i = 1;
    int ans = 1;
    
    while(i <= min(A, B)) {
        if(A % i == 0 && B % i == 0) {
            ans = i;
        }
        i++;
    }
    return ans;
}

