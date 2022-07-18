//                                                                   QUESTION

/*
Problem Description

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.



Input Format
The first and only argument given is the integer A.



Output Format
Return floor(sqrt(A))



Example Input
Input 1:

 11
Input 2:

 9


Example Output
Output 1:

 3
Output 2:

 3


Example Explanation
Explanation:

 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, so we return 3.
 */


//                                                                           ANSWER

int Solution::sqrt(int A) {
    long long s = 0, e = A, mid, ans;
    
    while(s <= e) {
        mid = (s + e) / 2;
        if(mid * mid == A) {
            return mid;
        }
        else if(mid * mid < A) {
            s = mid + 1;
            ans = mid;
        }
        else {
            e = mid - 1;
        }
    }
    
    return ans;
}
