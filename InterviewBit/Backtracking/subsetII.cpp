//                                                                          QUESTION


/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :

If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]
*/


//                                                                            ANSWER


void helper(vector<int> &nums, int x, vector<vector<int>> &res, vector<int> &ans) {
    res.push_back(ans);
    for(int i = x; i != nums.size(); i++) {
        if(i == x || nums[i] != nums[i - 1]) {
            ans.push_back(nums[i]);
            helper(nums, i + 1, res, ans);
            ans.pop_back();
        }
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> res;
    vector<int> ans;
    helper(A, 0, res, ans);
    return res;
}
