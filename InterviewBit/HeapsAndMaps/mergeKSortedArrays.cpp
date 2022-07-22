//                                                                   QUESTION

/*
You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.



Problem Constraints
1 <= K, N <= 103

0 <= A[i][j] <= 108

A[i][j] <= A[i][j+1]



Input Format
First and only argument is an 2D integer matrix A.



Output Format
Return a integer array denoting the merged array you get after merging all the arrays in A.



Example Input
Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]


Example Output
Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


Example Explanation
Explanation 1:

 You need to merge [1, 2, 3] , [2, 4, 6] and [0, 9, 10]  into a single array
 so the merged array will look like [0, 1, 2, 2, 3, 4, 6, 9, 10]
 */


//                                                                          ANSWER

vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>>min_h;
    
    for(int i = 0; i < A.size(); i++) {
        int col = A[i].size();
        int j = 0;
        while(j < col) {
            min_h.push(A[i][j]);
            j++;
        }
    }
    
    while(min_h.size() != 0) {
        ans.push_back(min_h.top());
        min_h.pop();
    }
    
    return ans;
}
