#include <bits/stdc++.h>
using namespace std;



// DECIMAL(int) TO BINARY(string)
// TC : O(log n)
// SC : O(1)
string toBinary(int n) {
    if (n == 0) return "0";    
    string res = "";
    while (n) {
        res = char((n % 2) + '0') + res;
        n /= 2;
    }
    return res;
}
// TC : O(logn)
// SC : O(logn)
string toBinary(int n) {
    string res = "";
    while (n) {
        if(n % 2 == 0) res += "0";
        else res += "1";
        n /= 2;
    }
    reverse(res.begin(), res.end()); // O(x) but x = logn becuz len of res = logn
    return res;
}



// BINARY(string) TO DECIMAL(int)
// TC : O(n)
// SC : O(1)
int toDecimal(string &binary){
    int value = 0;
    for(char bit : binary){
        value = (value << 1) + (bit - '0');
    }
    return value;
}
int toDecimal(string &x){
    int res = 0;
    int p2 = 1;
    for(int i=x.size()-1; i>=0; i--){
        if(x[i] == '1'){
            res += p2;
        }
        p2 *= 2;
    }
    return res;
}