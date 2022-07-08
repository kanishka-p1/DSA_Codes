void recur(string A, int B, string& res) {
    if(B == 0) {
        if(res < A) {
            res = A;
        }
        return;
    }
    
    for(int i = 0; i < A.length(); i++) {
        for(int j = i + 1; j < A.length(); j++) {
            swap(A[i], A[j]);
            recur(A, B - 1, res);
            swap(A[i], A[j]);
        }
    }
}

string Solution::solve(string A, int B) {
    string res = "";
    recur(A, B, res);
    return res;
}
