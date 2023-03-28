/******************************************************************************* QUESTION *****************************************************************************/

/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand of size N where hand [ i ] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, 
or false otherwise.

Example 1:
Input:
N = 9
groupSize = 3
hand[ ] = {1, 2, 3, 6, 2, 3, 4, 7, 8}
Output: true
Explanation: 
Alice's hand can be rearranged as {1, 2, 3} , {2, 3, 4}, {6, 7, 8}.
 
Example 2:
Input:
N = 5
groupSize = 2
hand[ ] = {1, 2, 3, 4, 5}
Output: false
Explanation: 
Alice's hand cannot be rearranged into groups of 2.
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function isStraightHand() which takes the interger N, integer groupSize and an 
integer array hand as parameters and returns the true if specified arrangement is possible.

Expected Time Complexity: O(Nlog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
1 ≤ groupSize ≤ N
0 ≤ handi ≤ 109
*/

/****************************************************************************** ANSWER *****************************************************************************/

class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> mp;
        for(auto it : hand) {
            mp[it]++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : mp) {
            pq.push(it.first);
        }
        
        while(!pq.empty()) {
            int temp = pq.top();
            for(int i = temp; i < temp + groupSize; i++) {
                if(mp.find(i) == mp.end()) {
                    return false;
                }
                mp[i]--;
                if(mp[i] == 0) {
                    if(i != pq.top()) {
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        return true;
    }
};
