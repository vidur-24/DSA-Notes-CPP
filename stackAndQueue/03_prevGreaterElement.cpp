#include <bits/stdc++.h>
using namespace std;


class Solution { 
public:
    vector<int> prevGreaterElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge(n, -1);
        stack<int> st; // monotonic stack

        // traverse left → right
        for(int i=0; i<n; i++){  
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top();

            st.push(nums[i]);
        }

        return pge;
    }
// tc: O(n + n) = for and while
// sc: O(n + n) = nge + st
};
