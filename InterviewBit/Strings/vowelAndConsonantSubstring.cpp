int Solution::solve(string A) {
    int size = A.size();
    
    if(size == 1)
        return 0;
    
    long long int vow = 0, con = 0;
    
    for(int i = 0; i < size; i++) {
        if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u') {
            vow++;            
        }
        else {
            con++;            
        } 
    }
    
    long long int ans = vow * con % 1000000007;
    
    return ans;
}
