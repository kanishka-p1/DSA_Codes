//                                                                            QUESTION

/*
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.
*/


//                                                                          ANSWER

//approach 1(accepted)

int Solution::largestRectangleArea(vector<int> &A) {
    int res = 0;
    A.push_back(0);
    
    stack<int> st;
    
    for(auto i=0; i<A.size(); i++)
    {
        if(st.empty() || A[i] >= A[st.top()])
            st.push(i);
        else
        {
            int j = st.top();
            int w;
            st.pop();
            if(st.empty()) {
                w = i;
            }
            else {
                w = i - st.top() - 1;
            }
            res = max(res, A[j] * w);
            i--;
        }
    }
    
    return res;
}


//approach 2 (works on leetcode bt fails for hard test case on interviewbit) 

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) {
            return 0;
        }
        vector<int> left(n);
        vector<int> right(n);
        
        int area = 0;
        
        left[0] = -1;
        right[n - 1] = n;
        
        for(int i = 1; i < n; i++) {
            int prev = i - 1;
            while(prev >= 0 && heights[prev] >= heights[i]) {
                prev = left[prev];
            }
            left[i] = prev;
        }
        
        for(int i = n - 2; i >= 0; i--) {
            int prev = i + 1;
            while(prev < n && heights[prev] >= heights[i]) {
                prev = right[prev];
            }
            right[i] = prev;
        }
        
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            area = max(area, heights[i] * width);
        }
        
        return area;
    }
};
