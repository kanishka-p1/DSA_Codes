//                                                                    QUESTION

/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Problem Description
 
 

Another question which belongs to the category of questions which are intentionally stated vaguely.

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

strstr - locate a substring ( needle ) in a string ( haystack ).

Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

NOTE: String A is haystack, B is needle.

Good clarification questions:

What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases.
*/


//                                                                            ANSWER


int Solution::strStr(const string A, const string B) {
    int m = A.length();
    int n = B.length();
    
    if(A.length() == B.length() && A == B)
    return 0;
    
    for(int i = 0; i < m - n; i++) {
        int j = 0;
        for(; j < n; j++) {
            if(A[i + j] != B[j]) {
                break;
            }
        }
        
        if(j == n) {
            return i;
        }
    }
    return -1;
}
