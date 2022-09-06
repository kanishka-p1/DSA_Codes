//                                                                           QUESTION

/*
Find the intersection of two sorted arrays. OR in other words, Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example:

Input:
    A: [1 2 3 3 4 5 6]
    B: [3 3 5]


Output: [3 3 5]



Input:
    A: [1 2 3 3 4 5 6]
    B: [3 5]



Output: [3 5]

NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays 
should be included multiple times in the final output. 
*/


//                                                                             ANSWER

vector<int> Solution::intersect(const vector<int> &nums1, const vector<int> &nums2) {
    unordered_map<int, int> freq;
    vector<int> ans;
    for(int x : nums1) {
        freq[x]++;            
    }
    for(int it : nums2) {
        if(--freq[it] >= 0) {
            ans.push_back(it);            
        }
    }
    return ans;
}
