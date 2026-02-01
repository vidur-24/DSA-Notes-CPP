#include <bits/stdc++.h>
using namespace std;

vector<int> minCoinChange(int coins[], int n, int amount){
    vector<int> result;
    sort(coins, coins + n, greater<int>()); // sort coins in descending order
    
    for(int i = 0; i < n; i++){
        while(amount >= coins[i]){
            amount -= coins[i];
            result.push_back(coins[i]); // if we wanted to count of coins, replace with -> cnt++;
        }
    }
    
    if(amount > 0){
        return {-1}; // not possible to make change
    }
    return result;
}
// TC : O(n log n) for sorting + O(n * m) for greedy selection, where m is the number of coins used
// SC : O(m) for storing the result


int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);\
    int amount = 9;

    vector<int> result = minCoinChange(coins, n, amount);
    if(result.size() == 1 && result[0] == -1){
        cout << "Not possible to make change for the amount " << amount << endl;
    } else {
        cout << "Coins used to make change for " << amount << ": ";
        for(int coin : result){
            cout << coin << " ";
        }
        cout << endl;
    }
    return 0;
}

// Note: - This greedy algorithm works optimally for the given coin denominations, because sum of any two coins doesnt equal any other coin
//       - if coins = {1, 5, 6, 9} and amount = 11, the greedy algorithm will return {9, 1, 1} which is not optimal, optimal is {6, 5}.
//       - This is because the greedy choice does not always lead to an optimal solution in all cases