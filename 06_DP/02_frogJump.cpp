// Question in gfg practice: https://www.geeksforgeeks.org/problems/geek-jump/1
// 1D DP problem

#include <bits/stdc++.h>
using namespace std;


class Solution { // space optimization
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        int prev1 = abs(height[1] - height[0]); // 1 step before
        int prev2 = 0; // 2 step before
        
        for(int i=2; i<n; i++){
            int left = prev1 + abs(height[i] - height[i-1]);
            int right = prev2 + abs(height[i] - height[i-2]);
            int curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }
        
        if(n==1) return prev2;
        return prev1; 
    }
};



class Solution { // tabulation
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        
        for(int i=2; i<n; i++){
            int left = dp[i-1] + abs(height[i] - height[i-1]);
            int right = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(left, right);
        }
        
        return dp[n-1];
    }
};



class Solution { // memoization
    int solve(int idx, vector<int> &height, vector<int> &dp){
        if(idx == 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int left = solve(idx-1, height, dp) + abs(height[idx] - height[idx-1]);
        if(idx == 1){
            return left;
        }
        int right = solve(idx-2, height, dp) + abs(height[idx] - height[idx-2]);
        
        dp[idx] = min(left, right);
        return dp[idx];
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        vector<int> dp(n+1, -1);
        return solve(n-1, height, dp);
    }
};



// Frog Jump with K distance : frog can jump to any of the next k stones (1, 2, 3, ..., k)
class Solution { // memoization
// TC : O(n*k)
// SC : O(n) + O(n) ~= O(n)
    int solve(int idx, vector<int> &height, int minSteps, int k, vector<int> &dp){
        if(idx == 0) return 0;

        if(dp[idx] != -1) return dp[idx];
        
        for(int j=1; j<=k; j++){
            if(idx - j >= 0){
                int jumpCost = solve(idx - j, height, minSteps, k, dp) + abs(height[idx] - height[idx - j]);
                minSteps = min(minSteps, jumpCost);
            }
        }

        dp[idx] = minSteps;
        return dp[idx];
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();

        vector<int> dp(n+1, -1); // memoization array
        dp[0] = 0; 
        int minSteps = INT_MAX;
        
        return solve(n-1, height, minSteps, 2, dp); 
    }
};
// similarly, tabulation
// for space optimisation, w ecan go to least O(k) space, using list in cpp (remove first element after each iteration and add curr)