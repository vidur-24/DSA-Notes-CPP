#include <bits/stdc++.h>
using namespace std;



class Solution { // Recursion
    int solve(int idx, int w, vector<int> &val, vector<int> &wt){
        if(idx == 0){
            if(wt[0] <= w) return val[0];
            return 0;
        }
        
        int notTake = 0 + solve(idx-1, w, val, wt);
        int take = -1e9;
        if(wt[idx] <= w) take = val[idx] + solve(idx-1, w-wt[idx], val, wt);
        
        return max(take, notTake);
    }
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        return solve(n-1, W, val, wt);
    }
};



class Solution { // Memoization
    int solve(int idx, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(idx == 0){
            if(wt[0] <= w) return val[0];
            return 0;
        }
        
        if(dp[idx][w] != -1) return dp[idx][w];
        
        int notTake = 0 + solve(idx-1, w, val, wt, dp);
        int take = -1e9;
        if(wt[idx] <= w) take = val[idx] + solve(idx-1, w-wt[idx], val, wt, dp);
        
        return dp[idx][w] = max(take, notTake);
    }
public:
int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(w+1, -1));
        return solve(n-1, w, val, wt, dp);
    }
};



class Solution { // Tabulation
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int w=wt[0]; w<=W; w++) dp[0][w] = val[0]; // for wt >= wt[0] ans is val[0]
        
        for(int idx=1; idx<n; idx++){
            for(int w=0; w<=W; w++){
                int notTake = 0 + dp[idx-1][w];
                int take = -1e9;
                if(wt[idx] <= w) take = val[idx] + dp[idx-1][w-wt[idx]];
                dp[idx][w] = max(take, notTake);
            }
        }
        return dp[n-1][W];
    }
};



class Solution { // space optimization
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<int> prev(W+1, 0);
        for(int w=wt[0]; w<=W; w++) prev[w] = val[0]; // for wt >= wt[0] ans is val[0]
        
        for(int idx=1; idx<n; idx++){
            vector<int> curr(W+1, 0);
            for(int w=0; w<=W; w++){
                int notTake = 0 + prev[w];
                int take = -1e9;
                if(wt[idx] <= w) take = val[idx] + prev[w-wt[idx]];
                curr[w] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};