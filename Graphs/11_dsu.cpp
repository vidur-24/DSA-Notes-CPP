#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) or Union-Find data structure
// - to know if two elements are in the same set (2 nodes belong to the same component)
// - if we use bfs/dfs, we get linear tc O(n + m) for traversing the graph, whereas dsu finds in O(1)
// - useful in dynamic graphs (constantly changing)

// - 2 main operations: find and union
// - find: find the root (ultimate parent) of the set containing the element
// - union: merge two sets

// - union has two variants: 
// 1. union by rank (rank : number of levels of that node beneath it)
// 2. union by size (size : number of nodes in that component, beneath it)

class DSU{
    vector<int> parent, rank, size;
public:
    DSU(int n){ // n = number of nodes (1-indexed)
        rank.resize(n+1, 0); // rank of each node is initially 0
        size.resize(n+1, 1); // size of each component is initially 1 (each node is its own component)
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i; // each node is its own parent initially
        }
    }


    // Find ultimate parent of a node -> find(u)
    // TC : O(4*alpha(n)) ~ O(1) (alpha is the inverse Ackermann function, very slow growing)
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]); // path compression
    }
    // path compression: makes the tree flat by making all nodes point to the root directly



    // Union by rank/size -> union(u,v)
    // step-1: find ultimate parent of u and v, pu and pv
    // step-2: find rank of pu and pv
    // step-3: connect smaller rank/size to larger rank/size always
    // TC : O(4*alpha(n)) ~ O(1) (same as findUParent for both rank/size) 



    void unionByRank(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return; // already in the same set

        // union by rank
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu; // make one root the parent of the other
            rank[pu]++; // increase the rank of the new root
        }
    }
    // why connect smaller to larger? 
    // -> so that the height of the tree remains small for more number of nodes, so takes less time to compute the findUParent operation
    // -> more nodes takes lesser time and less nodes will take more time, so we connect smaller to larger



    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return; // already in the same set

        // union by size
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu]; // increase the size of the new root
        }
        else{
            parent[pv] = pu; 
            size[pu] += size[pv]; // increase the size of the new root
        }
    }
};

int main(){
    DSU ds1(7);
    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);
    if(ds1.findUParent(3) == ds1.findUParent(7)) {
        cout << "3 and 7 are in the same set" << endl;
    } else {
        cout << "3 and 7 are not in the same set" << endl;
    }
    ds1.unionBySize(3, 7);
    if(ds1.findUParent(3) == ds1.findUParent(7)) {
        cout << "3 and 7 are in the same set" << endl;
    } else {
        cout << "3 and 7 are not in the same set" << endl;
    }
    return 0;
}