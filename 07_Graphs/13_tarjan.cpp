#include <bits/stdc++.h>
using namespace std;


// TARJAN'S ALGORITHM FOR BRIDGES/ARTICULATION-POINTS IN GRAPHS:
// - Tarjan's Algo of time in and low time (based on dfs): used to find bridges/articulation-points
// - Bridge = an edge, which removed, breaks graph into 2 or more components
// - Articulation Points = nodes on whose removal graph breaks into 2 or more components


// NOTE : there is also a TARJAN'S ALGORITHM for SCCs in directed graphs


// 1. Find Bridges in a Graph
class Solution { 
// SC: O(V+2E) -> for adj + O(3V) -> for tin, low, visited
// TC: O(V+E) -> for dfs

    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited, int tin[], int low[], vector<vector<int>> &bridges){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!visited[it]){ // if not visited
                dfs(it, node, adj, visited, tin, low, bridges); // perform dfs
                low[node] = min(low[node], low[it]); // update low
                
                // node---it : check if node-it link is a bridge
                if(low[it] > tin[node]){ // MAIN CONDITION: means it cannot reach parent or any of its ancestors via adj nodes, so node-it is a bridge
                    bridges.push_back({it, node});
                }
            }
            else{ // if already visited, then that link not a bridge (back edge)
                low[node] = min(low[node], low[it]); // update low
            }
        }
    }
public:
    vector<vector<int>> findBridges(int n, vector<vector<int>>& adj) {
        int tin[n]; // dfs time insertion
        int low[n]; // min lowest time insertion of all adj nodes apart from parent
        // apart from parent -> to know if we can reach via adj nodes towards parent, to check if its a bridge or not
        vector<int> visited(n, 0);
        vector<vector<int>> bridges; // contains the bridges

        dfs(0, -1, adj, visited, tin, low, bridges);
        return bridges;
    }
};



// 2. Find Articulation Points in a Graph
class Solution {
// SC: O(V + 2E) -> for adj + O(3V) -> for tin, low, visited
// TC: O(V + E) -> for dfs + O(V) -> for preparing ans

    int timer = 0;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, int tin[], int low[], vector<int> &mark){
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        int child = 0; // for root node check
        
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!visited[it]){ // if not visited
                dfs(it, node, adj, visited, tin, low, mark); // perform dfs
                low[node] = min(low[node], low[it]); // update low
                
                // check if node is a articulation point
                if(low[it] >= tin[node] && parent != -1){ // MAIN CONDITION: means it cannot reach parent or any of its ancestors via adj nodes and has lowest insertion time via parent only(=), so node is a articulation point
                    mark[node] = 1;
                }
                
                child++;
            }
            else{ // if already visited, them min of low time of node and insertion time of it
                low[node] = min(low[node], tin[it]); // special case for visited: update low
            }
        }
        
        if(child > 1 && parent == -1){ // specal case for root node, if it has more than 1 child, then it is an articulation point
            mark[node] = 1;
        }
    } 
public:
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        int tin[n]; // store the time of insertion during dfs
        int low[n]; // min lowest time insertion of all adj nodes apart from parent and visited nodes
        // apart from parent -> to know if we can reach via adj nodes towards parent
        // apart from visited nodes -> for visited we take the min(low[node], tin[it]), cuz if we remove visited node, then we reach the parent node, so it is not a articulation point
        vector<int> visited(n, 0);
        vector<int> mark(n, 0); // marks the articulation points, cuz we can have same node as articulation point in multiple dfs calls, so we need to mark it only once

        for(int i=0; i<n; i++){ // to handle disconnected components
            if(!visited[i]){
                dfs(i, -1, adj, visited, tin, low, mark);
            }
        }
        
        vector<int> ans; // prepare ans
        for(int i=0; i<n; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1}; // if no articulation points found, return -1
        return ans;
    }
};