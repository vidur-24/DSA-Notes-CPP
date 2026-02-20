#include <bits/stdc++.h>
using namespace std;

// shortest path in DAG using TOPO SORT


class Solution {
    void topoSort(int node, vector<pair<int,int>> adj[], int visited[], stack<int> &st){
        visited[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!visited[v]){
                topoSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }

public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<pair<int,int>> adj[N]; // pair in adjList for weighted graphs
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }


        // Step-1: find topo sort
        // O(N + M)
        int visited[N] = {0};
        stack<int> st;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                topoSort(i, adj, visited, st);
            }
        }

        // Step-2: do the distance thing (relaxation)
        // O(N + M)
        vector<int> dist(N, INT_MAX);
        dist[0] = 0; // dist[src] if src given
        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;

                // relaxation
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1; // if not reachable -1
            }
        }
        return dist;
    }
};

