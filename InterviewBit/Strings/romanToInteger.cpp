//                                                                          QUESTION


/*
Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/


//                                                                           ANSWER


int Solution::romanToInt(string A) {
    map<int, int> temp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    int sum = 0;
    int i = 0;
    
    while(i < A.size() - 1) {
        if(temp[A[i]] < temp[A[i + 1]]) {
            sum -= temp[A[i]];
        }
        else {
            sum += temp[A[i]];
        }
        i++;
    }
    sum += temp[A[i]];
    
    return sum;
}
