/************************************************************************* QUESTION **********************************************************************************/

/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4
 
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/

/*************************************************************************** ANSWER *********************************************************************************/

class Solution {
public:
    vector<int> rightSmallerElement(vector<int>& arr, int n) {
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

    vector<int> leftSmallerElement(vector<int>& arr, int n) {
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

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

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
};
