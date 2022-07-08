int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> freq;
    int count = 0;
    
    for(int i = 0; i < A.size(); i++) {
        freq[A[i]]++;
    }
    
    for(auto it : A) {
        if(freq.find(it ^ B) != freq.end()) {
            count += freq[it] * freq[it ^ B];
            freq[it] = 0;
            freq[it ^ B] = 0;
        }
    }
    
    return count;
}
