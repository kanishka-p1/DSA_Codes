/********************************************************************* QUESTION ****************************************************************************************/

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and 
adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106
*/

/**************************************************************************** ANSWER ********************************************************************************/

class Solution
{
	public:
 // first dfs to store in stack 
	void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
	    vis[node] = 1;
	    for(auto it : adj[node]) {
	        if(!vis[it]) {
	            dfs(it, vis, adj, st);
	        }
	    }
	    st.push(node);
	}
	
 // dfs to count the scc
	void dfstwice(int node, vector<int>& vis, vector<int> tadj[]) {
	    vis[node] = 1;
	    for(auto it : tadj[node]) {
	        if(!vis[it]) {
	            dfstwice(it, vis, tadj);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
     // to store the nodes in stack according to their finishing time
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }
     
     // reversing the graph
        vector<int> tadj[V];
        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                // i -> it
                // it -> i
                tadj[it].push_back(i);
            }
        }
        
     // again performing dfs to count the scc in reversed graph
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfstwice(node, vis, tadj);
            }
        }
        
        return scc;
    }
};
