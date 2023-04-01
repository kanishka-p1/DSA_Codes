/*************************************************************************** QUESTION **********************************************************************************/

/*
Given an array of N integers and Q queries of indices, print the number of next greater elements(NGEs) to the right of the given index element. 
Example:
Input:  arr     = [3, 4, 2, 7, 5, 8, 10, 6]
        queries = 2
        indices = [0, 5]
Output:  6, 1
Explanation:  
The next greater elements to the right of 3(index 0)
are 4,7,5,8,10,6.  
The next greater elements to the right of 8(index 5)
is only 10.

Your Task:
You don't need to read or print anything. Your task is to complete the boolean function count_NGEs() which takes N, arr, queries and indices as the 
input parameter and returns a list NGEs[] where NGEs[i] stores the count of elements strictly greater than the current element (arr[indices[i]]) to 
the right of indices[i].

Expected Time Complexity: O(N * queries).
Expected Auxiliary Space: O(queries).

Constraints:
1 <= N <= 104
1 <= arr[i] <= 105
1 <= queries <= 100

0 <= indices[i] <= N - 1
*/

/***************************************************************************** ANSWER ********************************************************************************/

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
       vector<int> ans;
       for(auto it : indices) {
           int count = 0;
           for(int i = it+1; i < n; i++) {
               if(arr[i] > arr[it]) {
                   count++;
               }
           }
           ans.push_back(count);
       }
       return ans;
    }

};
