// int Solution::solve(vector<int> &A, int B) {
//     int n = A.size();
//     int i = 0;
//     int j = 1;
    
//     sort(A.begin(), A.end());
    
//     while(i < n && j < n) {
//         if(i != j && A[j] - A[i] == B) {
//             return 1;
//         }
//         else if(A[j] - A[i] < n) {
//             j++;
//         }
//         else {
//             i++;
//         }
//     }
    
//     return 0;
// }


int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> temp;
    
    for(int i = 0; i < A.size(); i++) {
        temp[A[i]]++;
    }
    
    for(int i = 0; i < A.size(); i++) {
        if(B == 0) {
            return (temp[A[i]] > 1);
        }
        else {
            int d = A[i] + B;
            if(temp.find(d) != temp.end()) {
                return true;
            }
        }
    }
    
    return false;
}
