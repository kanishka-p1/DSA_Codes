/************************************************************************* QUESTION ***********************************************************************************/

/*
A number N is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120,
Given a number N, the task is to return the list/vector of the factorial numbers smaller than or equal to N.

Example 1:
Input: N = 3
Output: 1 2
Explanation: The first factorial number is 
1 which is less than equal to N. The second 
number is 2 which is less than equal to N,
but the third factorial number is 6 which 
is greater than N. So we print only 1 and 2.
Example 2:
Input: N = 6
Output: 1 2 6
Explanation: The first three factorial 
numbers are less than equal to N but 
the fourth factorial number 24 is 
greater than N. So we print only first 
three factorial numbers.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function factorialNumbers() which takes an integer N as an input parameter and 
return the list/vector of the factorial numbers smaller than or equal to N.

Expected Time Complexity: O(K), Where K is the number of factorial numbers.
Expected Auxiliary Space: O(1)

Constraints:
1<=N<=1018
*/

/***************************************************************************** ANSWER **********************************************************************************/

class Solution
{
public:
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans;
        long long i = 1;
        long long prod = 1;
        while(prod <= N) {
            prod = prod * i;
            if(prod <= N) {
                ans.push_back(prod);
            }
            i++;
        }
        return ans;
    }
};
