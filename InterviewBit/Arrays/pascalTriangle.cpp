//                                                                          QUESTION

/*
Given numRows, generate the first numRows of Pascal's triangle.
Pascal's triangle : To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
Constraints:
0 <= numRows <= 25
*/


//                                                                            ANSWER


vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> pascal(A);
    for(int i = 0; i < A; i++) {
        pascal[i].resize(i+1);
        pascal[i][0] = pascal[i][i] = 1;
        for(int j = 1; j < i; j++) {
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
    return pascal;
}
