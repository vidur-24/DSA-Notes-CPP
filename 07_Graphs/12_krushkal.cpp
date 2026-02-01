#include <bits/stdc++.h>
using namespace std;


// KRUSHKAL'S ALGORITHM:
// - greedy algo
// - to find mst
// - only for undirected


class Solution {
// SC : O(2V + E) -> for parent and size arrays, and edges
// TC : O(ElogE) 
public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        for(auto &it : edges){ // make it {wt, u, v} format to sort acc to wt
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            it[0] = wt;
            it[1] = u;
            it[2] = v;
        }
        
        DSU ds(V);
        sort(edges.begin(), edges.end()); // sort edges by weight -> O(ElogE)
        int mstWt = 0;
        
        // O(E * α(V))
        for(auto it : edges){
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            
            if(ds.findUParent(u) != ds.findUParent(v)){ // doesnt belong to same component
                mstWt += wt; // add to mst
                ds.unionBySize(u,v); // add to forest
            }
        }
        return mstWt;
    }
};