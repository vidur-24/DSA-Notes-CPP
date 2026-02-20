#include <bits/stdc++.h>
using namespace std;


// Version 1
struct Item{
    int value;
    int weight;
};

bool comp(Item a, Item b){ // comparator function for sorting
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 >= r2;
}

double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, comp); // sort acc to ratio of value/weight (greedy)

    double tVal = 0;
    for(int i = 0; i < n; i++){
        if(W >= arr[i].weight){ // take whole part
            tVal += arr[i].value;
            W -= arr[i].weight;
        } 
        else{ // take fractional part
            tVal += (double)arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return tVal;
}

int main(){
    int W = 90; // capacity of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {100, 50}, {200, 50}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}

// TC : O(n log n) for sorting + O(n) for traversing the items = O(n log n)
// SC : O(1) for the sorting and O(n) for the array of items


// Version 2
class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> ratioIndex; // {value/weight, index}

        for (int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            ratioIndex.push_back({ratio, i});
        }

        sort(ratioIndex.rbegin(), ratioIndex.rend()); // sort in decreasing order of ratio

        double maxValue = 0.0;

        for (int i = 0; i < n; i++) {
            int idx = ratioIndex[i].second;
            if (capacity >= wt[idx]) {
                maxValue += val[idx];
                capacity -= wt[idx];
            } else {
                maxValue += ratioIndex[i].first * capacity;
                break;
            }
        }

        return maxValue;
    }
};