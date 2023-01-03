/***************************************************************** QUESTION *********************************************************************************************/

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the 
n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/

/***************************************************************************** ANSWER *********************************************************************************/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        //{node, dist}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({k, 0});
        while(!pq.empty()) {
            int node = pq.top().first;
            int dis = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;

                if(dis + adjWt < dist[adjNode]) {
                    dist[adjNode] = dis + adjWt;
                    pq.push({adjNode, dis + adjWt});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(i != k && dist[i] == 1e9) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
