//                                                                         QUESTION


/*
Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

Check the sample test case for reference.

Example:

Input 1:

"A man, a plan, a canal: Panama"

Input 2:

"race a car"

Output and Explanation 1:

1

The input string after ignoring spaces, and all special characters is "AmanaplanacanalPanama" which is a palindrome after ignoring the case.

Output and Explanation 2:

0

The input string after ignoring spaces, and all special characters is "raceacar" which is not a palindrome

 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/


//                                                                             ANSWER

int Solution::isPalindrome(string A) {
    for(int i = 0, j = A.length() - 1; i < j; i++, j--) {
        while(i < j && !isalnum(A[i])) {
            i++;
        }
        while(i < j && !isalnum(A[j])) {
            j--;
        }
        if(toupper(A[i]) != toupper(A[j])) {
            return false;
        }
    }
    return true;
}
