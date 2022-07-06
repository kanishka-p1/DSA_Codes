//APPROACH 1

class Solution {
public:
    
  //subset sum code
    vector<vector<bool>> subsetSum(vector<int>& nums, int range) {
        int n = nums.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(range + 1));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int j = 1; j <= range; j++) {
            dp[0][j] = false;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= range; j++) {
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp;
    }
    
    int minimumDifference(vector<int>& nums) {
      //sum will get us the range
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
      //we will get the array for half of the arnge which will form s1 and the rest will simply be range - s1
        vector<vector<bool>> sub = subsetSum(nums, (sum + 1) / 2);
        
      //now here we will store the valid sum which has a subset in the array so all the true values
        vector<int> temp;
        for(int i = 0; i < sub[nums.size()].size(); i++) {
            if(sub[nums.size()][i]) {
                temp.push_back(i);
            }
        }
        
      
      // we will minimize the diff by minimizing range - 2 * sum
        int mn = INT_MAX;
        for(int i = 0; i < temp.size(); i++) {
            mn = min(mn, sum - 2*temp[i]);
        }
        
        return mn;
    }
};

//APPROACH 2
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        int mn = INT_MAX;
        
        for(int j = sum / 2; j >= 0; j--) {
            if(dp[n][j]) {
                mn = sum - 2 * j;
                break;
            }
        }
        
        return mn;
    }
};
