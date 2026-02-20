#include <bits/stdc++.h>
using namespace std;

// Detect Cycle in Directed Graph


// Approach 1: Using DFS
class Solution {
// TC : O(V + E)
// SC : O(2V)
// we can also use single visited array (use 1 for visited and 2 for pathVisited)
    bool dfsCheck(int src, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited){
        visited[src] = 1;
        pathVisited[src] = 1;
        
        for(auto adjNode : adj[src]){
            if(!visited[adjNode]){
                if(dfsCheck(adjNode, adj, visited, pathVisited))
                    return true;
            }
            else if(pathVisited[adjNode]){ // if visited node is in the path, then cycle exists
                return true;
            }
        }
        pathVisited[src] = 0; // backtrack
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        for(int i=0; i<V; i++){ // for not connnected graph too
            if(!visited[i]){
                if(detect(i, adj, visited, pathVisited))
                    return true;
            }
        }
        return false;
    }
};


// Approach 2: Using BFS
class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
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

        int cnt = 0; // to count number of nodes in topo sort (or simply ans.size())
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                    q.push(adjNode);
            }
        }

        if(cnt == V){ // if valid topo sort, then cycle does not exist
            return false;
        }
        return true; // if not a valid topo sort, then cycle exists
    }
};