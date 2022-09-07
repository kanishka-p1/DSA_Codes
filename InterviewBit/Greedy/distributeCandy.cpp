//                                                                      QUESTION

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
*/


//                                                                            ANSWER

int Solution::candy(vector<int> &ratings) {
    int n = ratings.size();
        int candy = n, i = 1;
        while(i < n) {
            if(ratings[i] == ratings[i - 1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i - 1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) {
                    return candy;                    
                }
            }
            
            //For decreasing slope
            int valley = 0;
            while(i < n && ratings[i] < ratings[i - 1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
    return candy;
}
