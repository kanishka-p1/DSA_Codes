/**************************************************************************** QUESTION ******************************************************************************/

/*
Given and integer N.Calculate the sum of series 13 + 23 + 33 + 43 + … till N-th term.

Example 1:
Input:
N=5
Output:
225
Explanation:
13+23+33+43+53=225
Example 2:
Input:
N=7
Output:
784
Explanation:
13+23+33+43+53+63+73=784

Your Task:
You don't need to read input or print anything.Your task is to complete the function sumOfSeries() which takes the integer N as parameter and returns the sum of the 
cubes of the first N natural numbers.

Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)

Constraints:
1<=N<=50000
*/

/********************************************************************************* ANSWER ***************************************************************************/

class Solution {
  public:
    long long sumOfSeries(long long N) {
        // code here
        if(N == 0) {
            return 0;
        }
        return N*N*N + sumOfSeries(N-1);
    }
};
