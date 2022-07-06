string Solution::simplifyPath(string A) {
    string ans = "";
    int n = A.size();
    
    stack<string> stk;
    int i = 0;
    while(i < n) {
        while(i < n && A[i] == '/') {
            i++;
        }
        string t = "";
        int c = 0;
        while(i < n && A[i] == '.') {
            i++;
            c++;
        }
        if(c == 2 && !stk.empty()) {
            stk.pop();
        }
        if(c == 0) {
            while(i < n && A[i] != '/') {
                t.push_back(A[i]);
                i++;
            }
            if(t != "") {
                stk.push(t);
            }
        }
    }
    
    while(!stk.empty()) {
        string p = stk.top();
        reverse(p.begin(), p.end());
        p.push_back('/');
        ans.append(p);
        stk.pop();
    }
    if(ans == "") {
        ans.push_back('/');
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
