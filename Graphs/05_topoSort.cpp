#include <bits/stdc++.h>
using namespace std;

// Topological Sort
// - linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering
// - only possible for Directed Acyclic Graph (DAG)
// - can be more than one valid ordering


// Approach 1: Using DFS
class Solution {
// TC : O(V + E) , for directed graph (dfs)
// SC : O(2V)
    void topoDFS(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st){
        visited[node] = 1;
        
        for(auto adjNode : adj[src]){
            if(!visited[adjNode])
                topoDFS(adjNode, adj, visited, pathVisited)
        }
        st.push(node); // push on backtrack
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){ // for not connnected graph too
            if(!visited[i]){
                topoDFS(i, adj, visited, st);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


// Approach 2: Using BFS (Kahn's Algorithm)
class Solution {
// TC : O(V + E) , for directed graph (dfs)
// SC : O(2V)
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto adjNode : adj[i]){
                indegree[adjNode]++;
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){ // indegree 0 means no incoming edges, so it can be put at the starting of topo sort
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // node already added to the topo sort, so remove its edges from indegree of its adjacent nodes
            // and if any adjacent node has indegree 0, then add it to the queue
            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }
        return ans;
    }
};