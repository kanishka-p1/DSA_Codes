//                                                                  QUESTION


/*
Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.



Problem Constraints
3 <= |A| <= 105

 A[i] is always a lowercase character.



Input Format
First and only argument is an string A.



Output Format
Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.



Example Input
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can remove character ‘c’ to make string palindrome
Explanation 2:

 It is not possible to make this string palindrome just by removing one character 
 */


//                                                                          ANSWER


bool check(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int Solution::solve(string A) {
    int i = 0, j = A.length() - 1;
    if(check(A, i, j)) {
        return 1;
    }
    
    while(i <= j) {
        if(A[i] == A[j]) {
            i++;
            j--;
        }
        else {
            if(check(A, i+1, j) || check(A, i, j-1)) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    return 0;
}
