#include <bits/stdc++.h>
using namespace std;

// Approach 1:
class Solution {
    bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n) ; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    vector<int> primeFactors(int n) {
        vector<int> res;
        for (int i=2; i<=n; i++) {
            if(n % i == 0) {
                if(is_prime(i)) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};