//                                                                          QUESTION


/*
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer


Look at the example for clarification.



Problem Constraints
N belongs to the Integer limits.



Input Format
Input an Integer.



Output Format
Return a single integer denoting the reverse of the given integer.



Example Input
Input 1:

 x = 123


Input 2:

 x = -123


Example Output
Output 1:

 321


Ouput 2:

 -321


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
 */


//                                                                            ANSWER

/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int reverse(int A) {
    long int ans = 0;
    
    while(A) {
        ans = (ans * 10) + (A % 10);
        A = A / 10;    
    }
    
    if(ans > INT_MAX || ans < INT_MIN) {
        return 0;
    }
    
    return ans;
}
