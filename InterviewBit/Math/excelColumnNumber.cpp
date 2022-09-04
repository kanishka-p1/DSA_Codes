//                                                                          QUESTION

/*
Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100



Input Format
First and only argument is string A.



Output Format
Return an integer



Example Input
Input 1:

 "A"
Input 2:

 "AB"


Example Output
Output 1:

 1
Output 2:

 28


Example Explanation
Explanation 1:

 A -> 1
Explanation 2:

A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
*/


//                                                                             ANSWER


int Solution::titleToNumber(string A) {
    int ans = 0;
    for(auto it : A) {
        int d = it - 'A' + 1;
        ans = ans * 26 + d;
    }
    return ans;
}
