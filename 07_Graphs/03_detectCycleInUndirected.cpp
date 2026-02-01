#include <bits/stdc++.h>
using namespace std;

// Detect Cycle in Undirected Graph


// Approach 1: Using BFS
class Solution {
// TC : O(V + 2E) + O(V)(nodes + degrees + for loop)
// SC : O(V) + O(V)(queue + visited array) ~= O(V)

    bool detect(int src, vector<vector<int>>& adj, vector<int>& visited){
        visited[src] = 1;
        
        queue<pair<int, int>> q; // (node, parent)
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjNode : adj[node]){
                if(!visited[adjNode]){
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(adjNode != parent){ // if visited node not parent, then cycle exists
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){ // for not connnected graph too
            if(!visited[i]){
                if(detect(i, adj, visited)) return true;
            }
        }
        return false;
        
    }
};


// Approach 2: Using DFS
class Solution {
// TC : O(V + 2E) + O(V)(nodes + degrees + for loop)
// SC : O(V) + O(V) + O(V)(recursio stack + visited array + adj list) ~= O(V)

    bool detect(int node, int parent, vector<int> adj[], int visited[]){
        visited[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(!visited[adjNode]){
                if(detect(adjNode, node, adj, visited)){
                    return true;
                }
            }
            else if(adjNode != parent){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V]; // making adj list
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int visited[V] = {0};
        
        for(int i=0; i<V; i++){ // for not connnected graph too
            if(!visited[i]){
                if(detect(i, -1, adj, visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};