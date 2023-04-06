/******************************************************************************* QUESTION ******************************************************************************/

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

/******************************************************************************* ANSWER ********************************************************************************/

// METHOD 1

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        set<int> rows; 
        set<int> col;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    rows.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(rows.count(i) || col.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// METHOD 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> row(r, 0);
        vector<int> col(c, 0);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// METHOD 3 - FOR THE ELEMENTS 1 AND 0 ONLY STRIVER OPTIMAL APPROACH

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        // vector<int> row(r, 0); -> matrix[..][0]
        // vector<int> col(c, 0); -> matrix[0][..]
        int col0 = 1;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    // mark thr ith row
                    matrix[i][0] = 0;
                    // mark the jth col
                    if(j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(matrix[i][j] != 0) {
                    // check for row and col
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < c; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 = 0) {
            for(int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};
