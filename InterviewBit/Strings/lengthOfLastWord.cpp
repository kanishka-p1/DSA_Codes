int Solution::lengthOfLastWord(const string A) {
    int len = 0, end = A.length() - 1;
    
    while(end >= 0 && A[end] ==  ' ') {
        end--;
    }
    while(end >= 0 && A[end] != ' ') {
        len++;
        end--;
    }
    
    return len;
}
