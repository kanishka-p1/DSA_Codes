//                                                                        QUESTION


/*
Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are present in atleast 2 out of 3 lists.
*/


//                                                                            ANSWER


vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    vector<int> ans;
    map<int, int> mp;
    set<int> s1(A.begin(), A.end());
    set<int> s2(B.begin(), B.end());
    set<int> s3(C.begin(), C.end());
    
    for(auto it : s1) {
        mp[it]++;
    }
    for(auto it : s2) {
        mp[it]++;
    }
    for(auto it : s3) {
        mp[it]++;
    }
    
    for(auto it : mp) {
        if(it.second >= 2) {
            ans.push_back(it.first);
        }
    }
    
    return ans;
}
