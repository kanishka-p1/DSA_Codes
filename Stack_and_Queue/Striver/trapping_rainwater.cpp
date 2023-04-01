/************************************************************************** QUESTION ********************************************************************************/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

/***************************************************************************** ANSWER *********************************************************************************/

// OPTIMAL APPROACH
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        int lmax = 0;
        int rmax = 0;

        while(l <= r) {
            if(height[l] <= height[r]) {
                if(height[l] >= lmax) {
                    lmax = height[l];
                }
                else {
                    ans += lmax - height[l];
                }
                l++;
            }
            else {
                if(height[r] >= rmax) {
                    rmax = height[r];
                }
                else {
                    ans += rmax - height[r];
                }
                r--;
            }
        }

        return ans;
    }
};

//BRUTE
 long long trappingWater(int arr[], int n)
    {
        // code here
        int lmax[n],rmax[n];
        
        //Left maximum array
        lmax[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            lmax[i]=max(lmax[i-1],arr[i]);
        }
        
        //Right maximum array
        
        rmax[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            rmax[i]=max(rmax[i+1],arr[i]);
        }
        
        //Calculating total rain trapped water
        
        long long res=0;
        
        for(int i=0;i<n;i++)
        {
            res+=min(lmax[i],rmax[i])-arr[i];
        }
        return res;
    }
