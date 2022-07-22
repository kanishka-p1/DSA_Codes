//                                                                           QUESTION

/*
There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

Questions:

Q1. Does string contain whitespace characters before the number?

A. Yes

Q2. Can the string have garbage characters after the number?

A. Yes. Ignore it.

Q3. If no numeric character is found before encountering garbage characters, what should I do?

A. Return 0.

Q4. What if the integer overflows?

A. Return INT_MAX if the number is positive, INT_MIN otherwise.

Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.

If you do, we will disqualify your submission retroactively and give you penalty points.
*/


//                                                                        ANSWER

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int Solution::atoi(const string s) {
    int len = s.length();
    
    if(len == 0) {
        return 0;
    }
    
    int index = 0;
    
    while(index < len && s[index] == ' ') {
        index++;
    }
    
    bool isNegative = false;
    
    if(index < len) {
        if(s[index] == '-') {
            isNegative = true;
            index++;
        }
        else if(s[index] == '+') {
            index++;
        }
    }
    
    int result = 0;
    
    while(index < len && isDigit(s[index])) {
        int digit = s[index] - '0';
        
        if(result > (INT_MAX / 10) || (result == (INT_MAX / 10) && digit > 7)) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        
        result = (result * 10) + digit;
        
        index++;
    }
    
    return isNegative ? -result : result;
}
