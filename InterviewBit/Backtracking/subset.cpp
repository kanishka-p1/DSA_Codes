//                                                                        QUESTION

/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]
*/

//                                                                            ANSWER


void helper(vector<int>& nums, int x, vector<int>& res, vector<vector<int>>& ans) {
    ans.push_back(res);
    for(int i = x; i < nums.size(); i++) {
        res.push_back(nums[i]);
        helper(nums, i + 1, res, ans);
        res.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> res;
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    
    helper(A, 0, res, ans);
    return ans;
}
