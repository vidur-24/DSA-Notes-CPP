#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n, -1);
        stack<int> st; // monotonic stack

        // traverse left to right
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }

        return pse;
    }
// tc: O(n + n) = for and while
// sc: O(n + n) = nge + st
};



class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n, -1);

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[j] < nums[i]){
                    pse[i] = nums[j];
                    break;
                }
            }
        }

        return pse;
    }
// tc: O(n^2)
// sc: O(n)
};