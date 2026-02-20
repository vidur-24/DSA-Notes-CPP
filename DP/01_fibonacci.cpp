// 1D DP problem
// Fibonacci series using DP

#include <iostream>
#include <vector>
using namespace std;

// 1. TOP-DOWN APPROACH : RECURSION + MEMOIZATION
int fibonacci(int n, vector<int> &dpArray){
    // base case
    if(n <= 1){ 
        return n;
    }

    // if ans already calculated
    if(dpArray[n] != -1){
        return dpArray[n];
    }

    // if not calculated
    dpArray[n] = fibonacci(n-1, dpArray) + fibonacci(n-2, dpArray); // calculate and store it
    return dpArray[n];
}

int main(){
    int n = 6;

    vector<int> dpArray(n+1, -1); // memoization array (1D)

    cout << fibonacci(n, dpArray) << endl;

    return 0;
}
// TC : O(n)
// SC : O(n) + O(n) ~= O(n)
//   recursion depth + array



// 2. BOTTOM-UP APPROACH : TABULATION
int main(){
    int n = 6;

    vector<int> dpArray(n+1, -1); // table
    dpArray[0] = 0;
    dpArray[1] = 1;

    for(int i=2; i<=n; i++){
        dpArray[i] = dpArray[i-1] + dpArray[i-2];
    }

    cout << dpArray[n] << endl;

    return 0;
}

// TC : O(n)
// SC : O(n) -> table



// 3. SPACE OPTIMIZATION : using only variables
// prev2 -> prev1 -> curr
int main(){
    int n = 6;

    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        // dpArray[i] = dpArray[i-1] + dpArray[i-2];
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    if(n==0){
        cout << prev2 << endl;
    }
    cout << prev1 << endl;

    return 0;
}

// TC : O(n)
// SC : O(1) -> variables