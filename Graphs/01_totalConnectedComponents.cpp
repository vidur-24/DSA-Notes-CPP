#include <bits/stdc++.h>
using namespace std;


 // Total Number Of Connected Components


// Approach 1: Using DFS
class Solution {
// SC : O(3V)(visited + adj + recursion stack) ~= O(V)
// TC : O(V) + O(2E)(total degree) ~= O(V + E)

    void solveDFS(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                solveDFS(neighbour, adj, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();

        // adj list
        vector<vector<int>> adj(v);
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(v, 0);
        
        int count = 0;
        for(int i=0; i<v; i++){
            if(!visited[i]){
                count++;
                solveDFS(i, adj, visited);
            }
        }

        return count;
    }
};



// Approach 2: Using BFS
class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int v = isConnected.size();
            vector<int> visited(v, 0);
            int count = 0;
    
            for(int i = 0; i < v; i++) {
                if(!visited[i]) {
                    count++;
                    queue<int> q;
                    q.push(i);
                    visited[i] = 1;
    
                    while(!q.empty()) {
                        int node = q.front();
                        q.pop();
    
                        for(int j = 0; j < v; j++) {
                            if(isConnected[node][j] == 1 && !visited[j]) {
                                visited[j] = 1;
                                q.push(j);
                            }
                        }
                    }
                }
            }
    
            return count;
        }
    };
    