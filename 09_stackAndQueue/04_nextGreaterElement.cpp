#include <bits/stdc++.h>
using namespace std;


class Solution { 
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n, 0);
        stack<int> st; // monotonic stack

        // traverse right to left 
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(nums[i]);
        }

        return nge;
    }
// tc: O(n + n) = for and while
// sc: O(n + n) = nge + st
};