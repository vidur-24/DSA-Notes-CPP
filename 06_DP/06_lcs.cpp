#include <bits/stdc++.h>
using namespace std;


class Solution { // recursion
    int solve(int i, int j, string s1, string s2){
        if(i < 0 || j < 0) return 0; // no max common subseq

        if(s1[i] == s2[j]) return (1 + solve(i-1, j-1, s1, s2));

        return max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
    }
public:
int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return solve(n1-1, n2-1, text1, text2);
    }
// TC: O(2^m * 2*n)
// SC: O(m + n) 
};



class Solution { // memoization
    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0; // no max common subseq
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = (1 + solve(i-1, j-1, s1, s2, dp));
        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }
public:
int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solve(n1-1, n2-1, text1, text2, dp);
}
};



class Solution { // tabulation
    public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        
        // shifting of index by +1, so i and j means i-1 and j-1
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        for(int i=0; i<=n1; i++) dp[i][0] = 0;
        for(int j=0; j<=n2; j++) dp[0][j] = 0;
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = (1 + dp[i-1][j-1]);
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};



class Solution { // space optimize
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // shifting of index by +1, so i and j means i-1 and j-1
        vector<int> prev(n2+1, 0);
        // for(int j=0; j<=n2; j++) dp[0][j] = 0; // no need already 0

        for(int i=1; i<=n1; i++){
            vector<int> curr(n2+1, 0);
            // curr[0] = 0; // no need already 0
            for(int j=1; j<=n2; j++){
                if(text1[i-1] == text2[j-1]) curr[j] = (1 + prev[j-1]);
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
};