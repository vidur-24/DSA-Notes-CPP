// string matching using dp

#include <bits/stdc++.h>
using namespace std;


class Solution { // recursion
    int solve(int i, int j, string s, string t){
        if(j < 0) return 1; // string t matched
        if(i < 0) return 0; // string s exhausted

        if(s[i] == t[j]){
            int take = solve(i-1, j-1, s, t);
            int notTake = solve(i-1, j, s, t);
            return (take + notTake);
        }
        else{
            return solve(i-1, j, s, t); // not take
        }
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        return solve(m-1, n-1, s, t);
    }
// TC : O(2^m * 2^n)
// SC : O(m+n) = ass
};



class Solution { // memoization
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j < 0) return 1; // string t matched
        if(i < 0) return 0; // string s exhausted

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]){
            int take = solve(i-1, j-1, s, t, dp);
            int notTake = solve(i-1, j, s, t, dp);
            dp[i][j] = (take + notTake);
        }
        else{
            dp[i][j] = solve(i-1, j, s, t, dp); // not take
        }
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m-1, n-1, s, t, dp);
    }
// TC : O(m*n)
// SC : O(m*n) + O(m+n) = dp + ass
};



class Solution { // tabulation
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // shifting of idx
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0; i<=m; i++) dp[i][0] = 1;
        for(int j=1; j<=n; j++) dp[0][j] = 0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    long take = dp[i-1][j-1];
                    long notTake = dp[i-1][j];
                    dp[i][j] = (take + notTake);
                }
                else{
                    dp[i][j] = dp[i-1][j]; // not take
                }
            }
        }
        return dp[m][n];
    }
// TC : O(m*n)
// SC : O(m*n) = dp
};



class Solution { // so
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<int> prev(n+1, 0);
        prev[0] = 1;

        for(int i=1; i<=m; i++){
            vector<int> curr(n+1, 0);
            curr[0] = 1;
            for(int j=1; j<=n; j++){
                if(s[i-1] == t[j-1]){
                    long take = prev[j-1];
                    long notTake = prev[j];
                    curr[j] = (take + notTake);
                }
                else{
                    curr[j] = prev[j]; // not take
                }
            }
            prev = curr;
        }
        return prev[n];
    }
// TC : O(m*n)
// SC : O(n+1) = dp
};