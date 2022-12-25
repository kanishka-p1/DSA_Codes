#include<bits/stdc++.h>
using namespace std;

string findlcs(string s1, string s2, int n, int m) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(s1[i - 1] = s2[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = max(dp[i - 1][j],  dp[i][j - 1]);
      }
    }
  }
  
  string res = "";
  int i = n, j = m;
  while(i >= 0 && j >= 0) {
    if(s1[i - 1] == s2[j - 1]) {
      res.push_back(s1[i - 1]);
      i--;
      j--;
    }
    else {
      if(dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      }
      else{
        j--;
      }
    }
  }
  
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  string X = "agtgatg";
  string Y = "gttag";
  
  int n = X.length();
  int m = Y.length();
  
  string ans = findlcs(X, Y, n, m);
  cout << ans;
  
  return 0;
}
