#include <bits/stdc++.h>
using namespace std;


// Brute Force : generate(powerset or recursion) all subsequences and check

class Solution { // recursion
    int solve(int idx, int prevIdx, vector<int>& nums, int n){
        if(idx == n) return 0;

        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + solve(idx+1, idx, nums, n);
        }
        int notTake = 0 + solve(idx+1, prevIdx, nums, n);

        return max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return solve(0, -1, nums, n);
    }
};



class Solution { // memoization
    int solve(int idx, int prevIdx, vector<int>& nums, int n, vector<vector<int>> &dp){
        if(idx == n) return 0;

        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + solve(idx+1, idx, nums, n, dp);
        }
        int notTake = 0 + solve(idx+1, prevIdx, nums, n, dp);

        return dp[idx][prevIdx+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, n, dp);
    }
};



class Solution { // tabulation
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // [idx][prvidx]
        for(int j=0; j<=n; j++) dp[n][j] = 0;

        for(int idx=n-1; idx>=0; idx--){
            for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
                int take = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx+1][idx+1];
                }
                int notTake = 0 + dp[idx+1][prevIdx+1];

                dp[idx][prevIdx+1] = max(take, notTake);
            }
        }

        return dp[0][0];
    }
};



class Solution { // so
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ahead(n+1, 0);
        // for(int j=0; j<=n; j++) ahead[j] = 0;

        for(int idx=n-1; idx>=0; idx--){
            vector<int> curr(n+1, 0);
            for(int prevIdx=idx-1; prevIdx>=-1; prevIdx--){
                int take = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + ahead[idx+1];
                }
                int notTake = 0 + ahead[prevIdx+1];

                curr[prevIdx+1] = max(take, notTake);
            }
            ahead = curr;
        }

        return ahead[0];
    }
// TC: O(n^2)
// SC: O(n*2)
};



// another way of tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] signifies, lis till idx i
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
// TC: O(n^2)
// SC: O(n)
};



// print lis
class Solution { // another way of tabulation
public:
    vector<int> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1); // dp[i] signifies, lis till idx i
        vector<int> hash(n); // stores the prevIdx of i-th element
        int lastIdx = 0; // to store the last index of the maximum LIS found so far
        int maxi = 1; // to store the maximum length of LIS found so far
        for(int i=0; i<n; i++){
            hash[i] = i; // initialize hash with self index
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx) {
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



// another way using binary search
class Solution { 
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin(); 
                // In C++, lower_bound is a standard library function used to find the first position in a sorted range where a value can be inserted without violating the order — or in other words, the first element not less than a given value.
                temp[idx] = nums[i];
            }
        }
        return temp.size(); // temp is not lis
    }
// TC: O(nlogn)
// SC: O(n)
};