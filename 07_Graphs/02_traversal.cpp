#include <bits/stdc++.h>
using namespace std;

// Connected Components
// -> use visited array
// -> use for loop to traverse all nodes
for(int i=0; i<V; i++){
    if(!visited[i]){
        traversal(i);
    }
}




// Function to return Breadth First Traversal of given graph.
class Solution {
// SC = O(3V)(visited + result + queue) ~= O(V)
// TC = O(V) + O(2E)(total degree) ~= O(V + E)
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size(); // number of vertices (nodes)
        
        // visited array
        int visited[v] = {0};
        visited[0] = 1;
        
        // queue
        queue<int> q;
        q.push(0); // starting node
        
        // BFS traversal
        vector<int> result;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(auto neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        
        return result;
    }
};


// Function to return Depth First Traversal of given graph.
class Solution {
// SC : O(3V)(visited + result + recursion stack) ~= O(V) 
// TC : O(N ) + O(V + 2E) (for loop + dfs) ~= O(N)
    void solveDFS(int node, vector<vector<int>>& adj, int visited[], vector<int>& result){
        visited[node] = 1;
        result.push_back(node);
        
        // traverse all its neighbours
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                solveDFS(neighbour, adj, visited, result);
            }
        }
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size(); // number of vertices (nodes)
        
        int visited[v] = {0}; // visited array
        int startNode = 0; // starting node
        vector<int> result; // DFS traversal
        
        solveDFS(startNode, adj, visited, result);
        
        return result;
    }
};