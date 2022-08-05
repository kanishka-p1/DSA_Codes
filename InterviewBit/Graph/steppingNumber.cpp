//                                                                      QUESTION

/*
Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
 */


//                                                                            ANSWER

void dfs(vector<int>& ans, int a, int b, int i) {
    if(i >= a && i <= b) {
        ans.push_back(i);
    }
    if(i == 0 || i > b) {
        return;
    }
    
    int t = i % 10;
    int x = i * 10 + t - 1;
    int y = i * 10 + t + 1;
    
    if(t == 0) {
        dfs(ans, a, b, y);
    }
    else if(t == 9) {
        dfs(ans, a, b, x);
    }
    else {
        dfs(ans, a, b, x);
        dfs(ans, a, b, y);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    
    for(int i = 0; i <= 9; i++) {
        dfs(ans ,A, B, i);
    }
    sort(ans.begin(), ans.end());
    
    return ans;
}
