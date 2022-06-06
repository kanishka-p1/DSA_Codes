#include <string.h>
using namespace std;

void printAllPossibleCodesHelper(string input, string output)
{
    //int len = input.size();
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }
    int num = input[0] - 48;
    char ch = 'a' + num - 1;
    printAllPossibleCodesHelper(input.substr(1), output + ch);
    if(input[1] != '\0')
    {
        num = num * 10 + input[1] - 48;
        ch = num - 1 + 'a';
        if(num >= 10 && num <= 26)
        {
            printAllPossibleCodesHelper(input.substr(2), output + ch);
        }
    }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    printAllPossibleCodesHelper(input, "");
}
