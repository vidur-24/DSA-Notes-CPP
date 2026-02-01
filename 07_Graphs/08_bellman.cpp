#include <bits/stdc++.h>
using namespace std;

// BELLMAN-FORD ALGORITHM:
// - single source shortest path algorithm 
// - dynamic programming approach
// - detect -ve wt cycles (works for -ve wts) -> on Nth iteration, if we can still relax an edge, then there is a -ve wt cycle
// - works for directed graphs (for undirected, treat as directed with both directions)
// - relax all edges V-1 times sequentially (why n-1? see strivers)


class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // TC : O(V*E)
        for(int i=0; i<V-1; i++){ // v-1 iterations
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // relaxation
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // n-th relaxation to check -ve weight cycle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            // relaxation
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

