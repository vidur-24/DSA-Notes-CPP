#include <bits/stdc++.h>
using namespace std;

// PRIMS ALGORITHM:
// - greedy algo
// - find mst or mst wt
// - only for undirected



// 1. for sum of wt
class Solution {
// TC : O(ElogE)
// SC : O(E+V) -> pq + visited
public:
    int primsMST(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; // min-heap
        // {wt, node}
        vector<int> visited(V, 0);
        
        pq.push({0,0});
        int sum = 0;
        // O(E)
        while(!pq.empty()){
            // O(logE)
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int node = it.second;
            
            if(!visited[node]){
                visited[node] = 1;
                sum += d;
                
                // O(E)
                for(auto it : adj[node]){
                    int adjNode = it[0];
                    int wt = it[1];
                    
                    // O(logE)
                    if(!visited[adjNode]){
                        pq.push({wt, adjNode});
                    }
                }
            }
        }
        return sum;
    }
};