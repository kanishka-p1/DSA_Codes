/************************************************************************* QUESTION *************************************************************************************/

/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:
Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. 
The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only.
As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

/************************************************************************** ANSWER ***********************************************************************************/

class Solution{
  public:
    vector<int> rightSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> leftSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(int* heights, int n) {
        // int n = heights.size();

        vector<int> right(n);
        right = rightSmallerElement(heights, n);

        vector<int> left(n);
        left = leftSmallerElement(heights, n);

        int area = INT_MIN;

        for(int i = 0; i < n; i++) {
            int l = heights[i];

            if(right[i] == -1) {
                right[i] = n;
            }

            int b = right[i] - left[i] - 1;

            int newArea = l*b;
            area = max(area, newArea);
        }

        return area;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        // int n = matrix.size();
        // int m = matrix[0].size();

        // compute area for first row
        int area = largestRectangleArea(M[0], m);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // row update : by adding previous row's value
                if(M[i][j] != 0) {
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else {
                    M[i][j] = 0;
                }
            }
            // entire row is updated
            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;
    }
};
