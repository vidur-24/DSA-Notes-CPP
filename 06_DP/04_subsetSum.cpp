// DP on Subsequences/Subsets and target

// - subsequence/subset is a part of array (continuos or non-continuous)
// - subsequences = in order, subsets = may or may not be in order

// IMP : the dp array gives the answer for all targets from 0 to target

#include <bits/stdc++.h>
using namespace std;



class Solution { // Recursion
    bool solve(int idx, int target, vector<int> &arr){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        bool notTake = solve(idx-1, target, arr);
        bool take = false;
        if(arr[idx] <= target) take = solve(idx-1, target-arr[idx], arr);
        
        return (take || notTake);
    }
    public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        return solve(n-1, sum, arr);
    }
    // TC : O(2^n)
    // SC : O(n) = stk
};



class Solution { // Memoization
    bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool notTake = solve(idx-1, target, arr, dp);
        bool take = false;
        if(arr[idx] <= target) take = solve(idx-1, target-arr[idx], arr, dp);
        
        return dp[idx][target] = (take || notTake);
    }
    public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(n-1, sum, arr, dp);
    }
    // TC : O(n*target)
    // SC : O(n*target) + O(n)
};



class Solution { // Tabulation
    public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        for(int i=0; i<n; i++) dp[i][0] = true; // target 0 bc
        if(arr[0] <= sum) dp[0][arr[0]] = true; // last idx bc
        
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(arr[idx] <= target) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = (take || notTake);
            }
        }
        
        return dp[n-1][sum];
    }
    // TC : O(n*target)
    // SC : O(n*target)
};



class Solution { // space optimization
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum+1, 0);
        prev[0] = true; // target 0 bc
        if(arr[0] <= sum) prev[arr[0]] = true; // last idx bc
        
        for(int idx=1; idx<n; idx++){
            vector<bool> curr(sum+1, 0);
            curr[0] = true; // target 0 bc
            for(int target=1; target<=sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[idx] <= target) take = prev[target-arr[idx]];
                
                curr[target] = (take || notTake);
            }
            prev = curr;
        }
        
        return prev[sum];
    }
// TC : O(n*target)
// SC : O(target)
};
