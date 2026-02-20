// Problem Statement: Given N jobs where each job has a deadline and profit associated with it, find the maximum profit that can be earned by scheduling the jobs within their deadlines.

// Greedy Approach Intiution:
// - delay the job to the end days, so u can do more jobs before the deadline.
// - take the job with maximum profit first, so u can earn more profit.

#include <bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

bool comp(Job a, Job b){ // comparator to sort jobs by profit in descending order
    return a.profit > b.profit; 
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit){
    int n = deadline.size();

    vector<Job> jobs(n);
    for(int i = 0; i < n; i++){
        jobs[i].id = i; // 0-based index for job id
        jobs[i].dead = deadline[i];
        jobs[i].profit = profit[i];
    }

    sort(jobs.begin(), jobs.end(), comp); // sort jobs by profit in descending order
    
    int totalProfit = 0; // total profit earned
    int cnt = 0; // count of jobs done

    int maxDeadline = *max_element(deadline.begin(), deadline.end()); // find the maximum deadline
    // int maxDeadline = -1;
    // for(int d : deadline) {
    //     maxDeadline = max(maxDeadline, d);
    // }

    vector<int> slots(maxDeadline + 1, -1); // slots to keep track of jobs done, -1 means slot is empty
    // maxDeadline + 1 because we want to use 1-based indexing for slots

    for(int i = 0; i < n; i++){
        for(int j = jobs[i].dead; j > 0; j--){ // Find a slot for the job, starting from its deadline and going backwards
            if(slots[j] == -1){ // slot empty
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                cnt++;
                break;
            }
        }
    }
    return {cnt, totalProfit}; // return count of jobs done and total profit earned
    // slots contains the sequence in which the jobs need to be done
}
