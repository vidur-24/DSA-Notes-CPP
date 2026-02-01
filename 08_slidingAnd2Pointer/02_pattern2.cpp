#include <bits/stdc++.h>
using namespace std;


// longest subarray with atmost k zeroes

class Solution { // most optimized
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0, r=0, zeros=0, maxLen = 0;
        
        while(r < n){
            if(nums[r] == 0) zeros++;

            if(zeros > k){ // dont allow maxLen to get updated while zeros > k
                if(nums[l] == 0) zeros--;
                l++; // current size < maxLen
            }

            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }

            r++;
        }

        return maxLen;
    }
// tc: O(n) 
// sc: O(1)
};



class Solution { // optimized
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0, r=0, zeros=0, maxLen = 0;
        
        while(r < n){
            if(nums[r] == 0) zeros++;

            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }

            if(zeros <= k){
                int len = r-l+1;
                maxLen = max(maxLen, len);
            }

            r++;
        }

        return maxLen;
    }
// tc: O(n) + O(n) = outer + inner while
// sc: O(1)
};



class Solution { // brute
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxLen = 0;
        for(int i=0; i<n; i++){
            int zeros = 0;
            for(int j=0; j<n; j++){
                if(nums[j] == 0) zeros++;

                if(zeros <= k){
                    int len = j-i+1;
                    maxLen = max(maxLen, len);
                }
                else{
                    break;
                }
            }
        }
    }
// tc: O(n^2)
// sc: O(1)
};