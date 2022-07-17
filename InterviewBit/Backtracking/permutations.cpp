//                                                                       QUESTION

/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
NOTE

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

Example : next_permutations in C++ / itertools.permutations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/

//                                                                           ANSWER

void helper(vector<int>& arr, vector<vector<int>>& ans, int s, int e) {
    if(e == s) {
        ans.push_back(arr);
        return;
    }
    else {
        for(int i = s; i <= e; i++) {
            swap(arr[s], arr[i]);
            helper(arr, ans, s + 1, e);
            swap(arr[s], arr[i]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> ans;
    helper(A, ans, 0, n - 1);
    
    return ans;
}
