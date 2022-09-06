//                                                                        QUESTION

/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 

For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5
*/


//                                                                      ANSWER


double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = B.size();
    if(m > n) {
        return findMedianSortedArrays(B, A);
    }
    
    int l = 0, r = m;
    int total = m + n + 1;
    while(l <= r) {
        int fir = l + (r - l) / 2;
        int sec = total / 2 - fir;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(fir > 0) {
            l1 = A[fir - 1];
        }
        if(sec > 0) {
            l2 = B[sec - 1];
        }
        if((fir >= 0) && (fir < m)) {
            r1 = A[fir];
        }
        if((sec >= 0) && (sec < n)) {
            r2 = B[sec];
        }
        if(l1 <= r2 && l2 <= r1) {
            if((m+n) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else {
                return max(l1, l2);
            }
        }
        else if(l1 > l2) {
            r = fir - 1;
        }
        else {
            l = fir + 1;
        }
    }
    return 0;
}
