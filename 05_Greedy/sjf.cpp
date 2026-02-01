// SJF -> CPU Scheduling Algorithm

#include <bits/stdc++.h>
using namespace std;

class Solution {
// NOTE: all process arrives at time 0 (so SJF with no premption)
public:
    long long solve(vector<int>& bt) {
        int n = bt.size(); // total process
        
        sort(bt.begin(), bt.end()); // sjf
        
        int t=0; // it is basically TAT
        long long totalWT=0;
        
        for(int i=0; i<n; i++){
            totalWT += t;
            t += bt[i];
        }
        
        return (totalWT/n);
    }
};
// TC : O(n) + O(nlogn)
// SC : O(1)