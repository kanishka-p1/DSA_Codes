//                                                                    QUESTION

/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.




Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

//                                                                         ANSWER

const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const string rom[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string Solution::intToRoman(int A) {
    string ans = "";
    int i = 0;
    while(A) {
        while(A >= val[i]) {
            ans += rom[i];
            A -= val[i];
        }
        i++;
    }
    
    return ans;
}
