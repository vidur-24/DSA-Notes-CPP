#include <bits/stdc++.h>
using namespace std;

// DIJKSTRA'S ALGORITHM:
// - single source shortest path algorithm
// - works for directed and undirected graphs
// - greedy algorithm
// - min cost via each vertex
// - does not work for -ve wt or -ve wt cycles (infinite loop)


// - 3 ways to implement (from slowest to fastest): queue, priority queue (min heap), set
// set and pq almost same in terms of time complexity



// 1. Using priority queue (min heap)
class Solution {
// TC : O(E log V)
// SC : O(V + E) for adj list and dist array
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];
        for(int i=0; i<edges.size(); i++){ // make adj list
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});    
            adj[v].push_back({u, wt});    
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min-heap
        // {dist, node}
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                // relaxation (through the node just extracted from pq to its adj nodes)
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};


// 2. Using set
// - set is ascending order by default
class Solution {
// TC : O(E log V)
// SC : O(V + E) for adj list and dist array
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int,int>> adj[V];
        for(int i=0; i<edges.size(); i++){ // make adj list
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});    
            adj[v].push_back({u, wt});    
        }
        
        set<pair<int,int>> st; // set
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        st.insert({0,src});
        
        while(!pq.empty()){
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                // relaxation (through the node just extracted from pq to its adj nodes)
                if(d + wt < dist[adjNode]){
                    //erase if exists
                    if(dist[adjNode] != INT_MAX) { // differentiation from pq
                        st.erase({dist[adjNode], adjNode}); // depends on graph if set takes same time or less time than pq
                    }

                    dist[adjNode] = dist[node] + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};


// why pq, and not q?
// see striver



// print the shortest path (dijkstra)
class Solution {
// TC : O(E log V + V)
// SC : O(V + E) for adj list and dist array
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<pair<int,int>> adj[V+1]; // v+1 for 1-based indexing
        for(auto it : edges){ // make adj list
            adj[it[0]].push_back({it[1], it[2]});    
            adj[it[1]].push_back({it[0], it[2]}); 
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min-heap
        vector<int> dist(V+1 INT_MAX);
        
        // to print path
        vector<int> parent(V+1, -1); // to store the path
        for(int i=0; i<V+1; i++) parent[i] = i; // initialize parent

        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                // relaxation (through the node just extracted from pq to its adj nodes)
                if(d + wt < dist[adjNode]){
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node; // update parent
                }
            }
        }

        if(dist[dest] == INT_MAX) {
            return {-1}; // unreachable
        }

        // O(V) to backtrack the path
        vector<int> path;
        int node = dest;
        while(parent[node] != node) { // backtrack until we reach the source
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src); // add source at the end
        reverse(path.begin(), path.end()); // reverse the path to get from source to destination
        return path; // return the path from source to destination
    }
};