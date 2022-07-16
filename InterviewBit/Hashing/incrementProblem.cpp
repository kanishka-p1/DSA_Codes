//                                                                      QUESTION

/*
Given a stream of numbers A. On arrival of each number, you need to increase its first occurence by 1 and include this in the stream.

Return the final stream of numbers.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 10000



Input Format
First and only argument is the array A.



Output Format
Return an array, the final stream of numbers.



Example Input
Input 1:

A = [1, 1]
Input 2:

A = [1, 2]


Example Output
Output 1:

[2, 1]
Output 2:

[1, 2]


Example Explanation
Explanation 1:

 On arrival of the second element, the other element is increased by 1.
Explanation 2:

No increases are to be done.
*/

//                                                                           ANSWER


//approach1

vector<int> Solution::solve(vector<int> &nums) {
    unordered_map<int, int> mp;
    
    for(int i = 0; i < nums.size(); i++) {
        if(mp.find(nums[i]) == mp.end()) {
            mp[nums[i]] = i;
        }
        else {
            int ind = mp[nums[i]];
            mp.erase(nums[ind]);
            nums[ind] += 1;
            
            if(mp.find(nums[ind]) == mp.end()) {
                mp[nums[ind]] = ind;
            }
            else {
                if(mp[nums[ind]] >= ind) {
                    mp[nums[ind]] = ind;
                }
            }
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
            }
        }
    }
    
    return nums;
}



//Approach2

vector<int> Solution::solve(vector<int> &A) {
    vector<int> res;
    for(int i = 0; i < A.size(); i++)
    {
        auto it = find(res.begin(), res.end(), A[i]);
        if(it != res.end())
        {
            (*it)++;
            res.push_back(A[i]);
        }
        else
        {
            res.push_back(A[i]);
        }
    }
    return res;
}
