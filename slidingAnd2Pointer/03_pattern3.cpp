#include <bits/stdc++.h>
using namespace std;


// diff 2 pointer where we have to count
// concept similar to : LC.1248 & LC.930
class Solution {
    int solve(vector<int>& nums, int k){ // cnt subarrays with sum <= goal
        if(k < 0) return 0; // edge case only for these types question

        int n = nums.size();

        int l=0, r=0, cnt=0;
        unordered_map<int, int> hash;

        while(r < n){
            hash[nums[r]]++;
            
            while(hash.size() > k){
                hash[nums[l]]--;
                if(hash[nums[l]] == 0) hash.erase(nums[l]);
                l++;
            }
            
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
// tc: O(n+n)
// sc: O(n)
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (solve(nums, k) - solve(nums, k-1));
    }
// tc : O(4n + log(256)) = +hash access time 
// sc : O(2n)
};



// BRUTE : tocheck all subarrays
class Solution {    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        
        int cnt=0;
        unordered_map<int, int> hash;
        
        for(int i=0; i<n; i++){
            hash.clear();
            for(int j=i; j<n; j++){
                hash[nums[j]]++;
                if(hash.size() == k) cnt++;
                else if(hash.size() > k) break;
            }
        }
        
        return cnt;
    }
// tc : O(n^2 + log(256)) = +hash access time 
// sc : O(n)
};