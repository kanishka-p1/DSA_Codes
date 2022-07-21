//                                                                    QUESTION

/*
Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
*/

//                                                                      ANSWER

vector<int> Solution::getRow(int A) {
    vector<int> temp;
    temp.push_back(1);
    
    if(A == 0) {
        return temp;
    }
    
    vector<int> k = getRow(A - 1);
    int n = k.size();
    
    for(int i = 0; i < n - 1; i++) {
        temp.push_back(k[i] + k[i + 1]);
    }
    
    temp.push_back(1);
    
    return temp;
}
