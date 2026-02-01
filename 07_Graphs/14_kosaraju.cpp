#include <bits/stdc++.h>
using namespace std;

// KOSARAJU'S ALGORITHM FOR STRONGLY CONNECTED COMPONENTS IN GRAPHS:
// - A strongly connected component (SCC) is a maximal subgraph where every vertex is reachable from every other vertex
// - SCC is a concept in directed graph only
// - num of SCCs or print the SCCs


// Steps:
// 1. Do a DFS on the original graph and store the finishing times of each node in a stack.
// 2. Sort all the nodes acc to their finishing times in descending order.
// 3. Reverse the graph (transpose it).
// 4. Do a DFS on the transposed graph, processing nodes in the order of their finishing times from the stack.
// 5. Each DFS call in this step will give you one strongly connected component.


// 1. Num of SCCs
class Solution {
// TC : O(V + E) -> for dfs + O(V + E) -> for reversing graph + O(V + E) -> for dfs on transposed graph
// SC : O(V + E) -> for adj + O(V) -> for vis + O(V) -> for stack

    void dfsFT(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){ // dfs for finishing time
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfsFT(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    void dfs(int node, vector<vector<int>> &adjT, vector<int> &vis){
        vis[node] = 1;
        for(auto it : adjT[node]){
            if(!vis[it]){
                dfs(it, adjT, vis);
            }
        }
    }
public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<int> vis(n, 0);
        
        // 1. finishing time
        stack<int> st;
        for(int i=0; i<n; i++){ // store acc to finishing time (which come last in the dfs traversal is finished first)
            if(!vis[i]){
                dfsFT(i, adj, vis, st);
            }
        }
        
        // 2. graph reversal
        vector<vector<int>> adjT(n);
        for(int i=0; i<n; i++){ // reverse the graph (transpose)
            vis[i] = 0; // reset vis array
            for(auto it : adj[i]){
                // before: i --> it
                // after: it --> i
                adjT[it].push_back(i);
            }
        }
        

        // 3. do dfs on transposed graph acc to finishing time
        int scc = 0; // total num of SCCs
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs(node, adjT, vis);
            }
        }
        return scc;
    }
};

// 2. Print all SCCs
// store each SCC in a vector of vectors in above code in dfs function