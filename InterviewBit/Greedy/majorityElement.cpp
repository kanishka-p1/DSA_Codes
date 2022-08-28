//                                                                          QUESTION

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example :

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.
*/


//                                                                          ANSWER

int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int m = n / 2;
    unordered_map<int, int> freq;
    for(auto it : A) {
        freq[it]++;
    }
    for(int i = 0; i < n; i++) {
        if(freq[A[i]] > m) {
            return A[i];
        }
    }
    return 0;
}
