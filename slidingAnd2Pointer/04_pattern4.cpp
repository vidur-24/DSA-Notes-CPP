#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l=0, r=0, cnt=0;
        int sIdx = -1, minLen = 1e9;\
        
        int hash[256] = {0};
        for(int i=0; i<m; i++){
            hash[t[i]]++;
        }        

        while(r < n){
            if(hash[s[r]] > 0) cnt++; // found letter from t
            hash[s[r]]--;

            while(cnt == m){ // sliding left pointer untill to check for min cnt=m 
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIdx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--; // letter from t back
                l++;
            }

            r++;
        }

        return (sIdx == -1 ? "" : s.substr(sIdx, minLen));
    }
// tc : O(m + 2n)
// sc: O(256)
};



// BRUTE
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int l=0, r=0;
        int sIdx = -1, minLen = 1e9;
        

        for(int i=0; i<n; i++){
            int hash[256] = {0};
            int cnt = 0;
            for(int j=0; j<m; j++) hash[t[j]]++; 

            for(int j=i; j<n; j++){
                if(hash[s[j]] > 0) cnt++;
                hash[s[j]]--;

                if(cnt == m){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        sIdx = i;
                    }
                    break;
                }
            }
        }

        return (sIdx == -1 ? "" : s.substr(sIdx, minLen));
    }
// tc : O(m + 2n)
// sc: O(256)
};