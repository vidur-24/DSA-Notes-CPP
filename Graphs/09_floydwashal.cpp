#include <bits/stdc++.h>
using namespace std;

// FLOYD-WARSHALL ALGORITHM:
// - all pairs shortest path algorithm
// - dynamic programming approach
// - detects -ve wt cycles
// - for directed graphs (for undirected graphs, treat as directed)
// - here we use adj matrix


class Solution {
// TC : O(v^3)
// SC : O(v^2)
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 1e8; // for overflow
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] < INF && dist[via][j] < INF){
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        
        // to detect a -ve wt cycle : there will be cyle to node itself, so - ve wt cycle will be < 0 (for diagonal elememt)

        // for(int i=0; i<n; i++){
        //     if(cost[i][i] < 0){
        //         // print -ve wt cycle
        //     }
        // }
        
        // return dist; // in-place
    }
};

// FOR MAKING ADJACENCY MATRIX (from edges):
// vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
// for(auto it : edges){ // make adj matrix (undirected graph)
//     dist[it[0]][it[1]] = it[2];
//     dist[it[1]][it[0]] = it[2];
// }
// for(int i = 0; i < n; i++) {
//     dist[i][i] = 0; // distance to self is 0
// }
