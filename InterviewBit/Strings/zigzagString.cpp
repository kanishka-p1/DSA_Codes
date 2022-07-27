//                                                                          QUESTION

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.
*/


//                                                                             ANSWER


string Solution::convert(string A, int B) {
    vector<string> v(B, "");
    int n = A.size();
    int i = 0;
    
    while(i < n) {
        for(int j = 0; j < B && i < n; j++) {
            v[j].push_back(A[i++]);
        }
        for(int j = B - 2; j >= 1 && i < n; j--) {
            v[j].push_back(A[i++]);
        }
    }
    
    string ans = "";
    for(auto it : v) {
        ans += it;
    }
    
    return ans;
}
