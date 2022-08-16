//                                                                      QUESTION

/*
The count-and-say sequence is the sequence of integers beginning as follows: 
1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11. 11 is read off as two 1s or 21.
21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2, the sequence is 11.
*/


//                                                                      ANSWER

string Solution::countAndSay(int A) {
    if(A == 0) {
        return "";
    }
    string ans = "1";
    
    while(--A) {
        string curr = "";
        for(int i = 0; i < ans.size(); i++) {
            int count = 1;
            while((i + 1 < ans.size()) && (ans[i] == ans[i + 1])) {
                count++;
                i++;
            }
            curr += to_string(count) + ans[i];    
        }
        ans = curr;
    }
    return ans;
}
