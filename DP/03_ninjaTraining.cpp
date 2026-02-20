// Question: https://www.geeksforgeeks.org/problems/geeks-training/1
// 2D DP problem : very important

#include <bits/stdc++.h>
using namespace std;


class Solution { // Recursion
    // last (task done on prvs day) -> 0 = task0, 1 = task1, 2 = task2, 3 = no task on prvs day
    int solve(int day, int last, vector<vector<int>> &arr){
        if(day == 0){ // bc
            int maxi = 0;
            for(int task=0; task<3; task++){
                if(task != last){
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                    int point = arr[day][task] + solve(day-1, task, arr, dp);
                    maxi = max(maxi, point);    
                }
        }
        
        return maxi;
    }
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size(); // num of days
        return solve(n-1, 3, arr);
    }
};



class Solution { // Memoization
// TC : O(3*(n*4))
// SC : O(n) + O(n*4)
    // last (task done on prvs day) -> 0 = task0, 1 = task1, 2 = task2, 3 = no task on prvs day
    int solve(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp){
        if(day == 0){ // bc
            int maxi = 0;
            for(int task=0; task<3; task++){
                if(task != last){
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        
        if(dp[day][last] != -1){
            return dp[day][last];
        }
        
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                int point = arr[day][task] + solve(day-1, task, arr, dp);
                maxi = max(maxi, point);    
            }
        }
        
        return dp[day][last] = maxi;
    }
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size(); // num of days
        
        vector<vector<int>> dp(n, vector<int>(4, -1)); // n*4, cuz task 0,1,2,3(no task)
        
        return solve(n-1, 3, arr, dp);
    }
};



class Solution { // Tabulation
// last (task done on prvs day) -> 0 = task0, 1 = task1, 2 = task2, 3 = no task on prvs day
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size(); // num of days
        
        vector<vector<int>> dp(n, vector<int>(4, 0)); // n*4, cuz task 0,1,2,3(no task)
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]}); 

        for(int day=1; day<n; day++){
            for(int last=0; last<4; last++){
                // dp[day][last] = 0; // doubt use of this statement
                for(int task=0; task<3; task++){
                    if(task != last){
                        int point = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], point);    
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }
// TC : O(3*4*n)
// SC : O(4*n)
};



class Solution { // Tabulation
// last (task done on prvs day) -> 0 = task0, 1 = task1, 2 = task2, 3 = no task on prvs day
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size(); // num of days
        
        vector<int> prev(4, 0);
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]}); 

        for(int day=1; day<n; day++){
            vector<int> curr(4, 0);
            for(int last=0; last<4; last++){
                // curr[last] = 0; 
                for(int task=0; task<3; task++){
                    if(task != last){
                        int point = arr[day][task] + prev[task];
                        curr[last] = max(curr[last], point);    
                    }
                }
            }
            prev = curr;
        }
        return prev[3];
    }
// TC : O(3*4*n)
// SC : O(4)
};