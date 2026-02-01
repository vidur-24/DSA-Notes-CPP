#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n, -1);  
        stack<int> st; // monotonic stack

        // traverse from right to left
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }

        return nse;
    }
// tc: O(n + n) = for and while
// sc: O(n + n) = nge + st
};