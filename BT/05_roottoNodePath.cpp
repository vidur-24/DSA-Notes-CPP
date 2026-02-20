#include <bits/stdc++.h>
using namespace std;



class Solution {
    bool help(TreeNode* root, int x, vector<int> &res){
        if(!root) return false;
        
        res.push_back(root->val);
        
        // if node x found
        if(root->val == x) return true;
        if(help(root->left, x, res) || help(root->right, x, res)) return true;
        
        res.pop_back(); // backtrack if node x not found
        return false;
    }
public:
    vector<int> Solution::solve(TreeNode* A, int B) {
        vector<int> res;
        help(A, B, res);
        return res;
    }
};
