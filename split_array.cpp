bool splitArrayHelper(int* arr, int n, int start, int lsum, int rsum)
{ 
    if (start == n) 
        return lsum == rsum; 
    
    if (arr[start] % 5 == 0) 
        lsum += arr[start]; 
 
    else if (arr[start] % 3 == 0) 
        rsum += arr[start]; 
    else
        return splitArrayHelper(arr, n, start + 1, lsum + arr[start], rsum) 
           || splitArrayHelper(arr, n, start + 1, lsum, rsum + arr[start]); 
   
    return splitArrayHelper(arr, n, start + 1, lsum, rsum); 
} 
bool splitArray(int *input, int size) 
{    
    return splitArrayHelper(input, size, 0, 0, 0);
}
