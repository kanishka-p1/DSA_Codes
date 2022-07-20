//                                                                    QUESTION

/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/

//                                                                        ANSWER

int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    
    int i = 0;
    
    for(i = 0; i < B.size() - 1; i++) {
        if(B[i] == B[i + 1]) {
            break;
        }
    }
    
    return B[i];
}
