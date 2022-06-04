#include<cstring>
bool isSubSequence(char str1[], char str2[], int m, int n)
{     
    if (m == 0) return true; 
    if (n == 0) return false; 
    
    if (str1[m-1] == str2[n-1]) 
        return isSubSequence(str1, str2, m-1, n-1); 
  
    return isSubSequence(str1, str2, m, n-1); 
} 
bool checksequenece(char large[] , char*small) 
{
    int m = strlen(small);
    int n = strlen(large);
    bool ans = isSubSequence(small, large, m, n);
    return ans;
}
