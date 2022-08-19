//                                                                        QUESTION


/*
Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.
*/


//                                                                          ANSWER

bool helper(vector<int> temp, int s, int e, int target) {
    while(s <= e) {
        int mid = (s + e) / 2;
        if(temp[mid] == target) {
            return true;
        }
        else if(temp[mid] < target) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return false;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size();
    int col = A[0].size();
    
    for(int i = 0; i < row; i++) {
        if(helper(A[i], 0, col - 1, B)) {
            return true;
        }
    }
    return false;
}
