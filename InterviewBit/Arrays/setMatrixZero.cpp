//                                                             QUESTION

/*
Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:

Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]


Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]



Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]



Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]
*/


//                                                                           ANSWER

void Solution::setZeroes(vector<vector<int> > &matrix) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int r = matrix.size();
    int c = matrix[0].size();
    bool row = false, col = false;
        
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 0) {
                if(i == 0)
                    row = true;
                if(j == 0)
                    col = true;
                matrix[i][0] = matrix[0][j] = 0;                
            }
        }
    }
        
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
        
    if(row) {
        for(int j = 0; j < c; j++) {
            matrix[0][j] = 0;
        }
    }
        
    if(col) {
        for(int i = 0; i < r; i++) {
            matrix[i][0] = 0;
        }
    }
}
