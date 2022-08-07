//                                                                        QUESTION


/*
Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

Return this maximum xor value.



Problem Constraints
1 <= |A|, |B| <= 105

1 <= A[i], B[i] <= 109



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an integer denoting the maximum xor value as described in the question.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [4, 1, 2]


Example Output
Output 1:

 7


Example Explanation
Explanation 1:

 Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7
 */


//                                                                              ANSWER


int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size(), m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> v1, v2;
    
    int maxi=1;
    
    while(maxi<<1 <= A[n-1])maxi=maxi<<1;
    while(maxi<<1 <= B[m-1])maxi=maxi<<1;
    
    for(int i=n-1;i>=0;i--){
        if(A[i]>=maxi) {
            v1.push_back(A[i]);
        }
    }
    
    for(int j=m-1;j>=0;j--){
        if(B[j]>=maxi)v2.push_back(B[j]);
    }
    
    int ans=0;
    
    for(auto i: v1){
        int target=(maxi-1)-(i-maxi);
        auto it= lower_bound(B.begin(),B.end(),target);
        auto jt=it;
        if(it!=B.end()){
            ans=max(ans,i^(*it));
            ++it;
            if(it!=B.end()){
                ans=max(ans,i^(*it));
            }
        }
        if(jt!=B.begin()){
            --jt;
            ans=max(ans,i^(*jt));
        }
    }
    
    for(auto i: v2){
        int target=(maxi-1)-(i-maxi);
        auto it= lower_bound(A.begin(),A.end(),target);
        auto jt=it;
        
        if(it!=A.end()){
            ans=max(ans,i^(*it));
            ++it;
            if(it!=A.end()){
                ans=max(ans,i^(*it));
            }
        }
        if(jt!=A.begin()){
            --jt;
            ans=max(ans,i^(*jt));
        }
    }
    
    return ans;
}
