/************************************************************************** QUESTION **********************************************************************************/

/*
You are given an array arr of N integers representing a min Heap. The task is to convert it to max Heap.

A max-heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. 

Example 1:
Input:
N = 4
arr = [1, 2, 3, 4]
Output:
[4, 2, 3, 1]
Explanation:
The given min Heap:

          1
        /   \
      2       3
     /
   4

Max Heap after conversion:

         4
       /   \
      3     2
    /
   1
Example 2:
Input:
N = 5
arr = [3, 4, 8, 11, 13]
Output:
[13, 11, 8, 4, 3]
Explanation:
The given min Heap:

          3
        /   \
      4      8
    /   \ 
  11     13

Max Heap after conversion:

          13
        /    \
      11      8
    /   \ 
   4     3
 

Your Task:
Complete the function int convertMinToMaxHeap(), which takes integer N and array represented minheap as input and converts it to the array 
representing maxheap. You don't need to return or print anything, modify the original array itself.
Note: Only an unique solution is possible under the expected time complexity.

Expected Time Complexity: O(N * log N)
Expected Auxiliary Space: O(N)


Constraints:

1 <= N <= 105
1 <= arr[i] <= 109
*/

/******************************************************************************* ANSWER ****************************************************************************/

//User function Template for C++

class Solution{
public:
    void heapify(vector<int>& arr, int n, int i) {
        int lc = 2*i+1;  // left child of ith element
        int rc = 2*i+2;  // right child of ith element
        int par = i;   // to store the largest so far
        
        // storing the largest
        if(lc < n && arr[lc] > arr[par]) {
            par = lc;
        }
        if(rc < n && arr[rc] > arr[par]) {
            par = rc;
        }
        
        // if the largest is ot the parent element swap
        if(par != i) {
            swap(arr[i], arr[par]);
            heapify(arr, n, par);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        // we will start to heapify the elements from bottom to top from the 
        // last rightmost parent element so as to save n/2 iterations
        for(int i = (N-2)/2; i >= 0; i--) {
            heapify(arr, N, i);
        }
    }  
};
