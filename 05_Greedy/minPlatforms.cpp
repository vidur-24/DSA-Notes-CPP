// Function to find the minimum number of platforms required at the railway station such that no train waits.

#include <bits/stdc++.h>
using namespace std;

class Solution {
// TC : O(2N log N) for sorting + O(2N) for the loop
// SC : O(1)
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size(); // number of trains
        
        // sort independently arr and dep time
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i=0, j=0; // pointer for arr(i) and dep(j)
        int cnt=0, maxCnt=0;
        while(i < n){ // till all the train arrives
            if(arr[i] <= dep[j]){ // platform occupied
                cnt++;
                i++;
            }
            else{ // platform vacant
                cnt--;
                j++;
            }
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt; // max platform occupied at the same time
    }
};


// Why is it Greedy? -> Greedy algorithms make locally optimal decisions at each step, without backtracking.

// Here’s how this solution fits that:
// - It sorts both arrival and departure times.
// - It greedily assigns platforms based on which event (arrival or departure) comes next.

// At each step:
// - If the next train arrives before the earliest departing one → allocate a new platform.
// - Else → free up a platform.

// You're always making the locally best decision: “Can I reuse a platform now, or do I need a new one?”