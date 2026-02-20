#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // (col, row, nodes) or (vertical, level, nodes) -> nodes (if 2 or more nodes at 1 (i,j))
        
        queue <pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val); // insert in map

            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(auto p : nodes){ // for each vertical
            vector<int> col;
            for(auto q : p.second){ // insert nodes from level wise i.e, top to bottom
                col.insert(col.end(), q.second.begin(), q.second.end()); // insert all the nodes at that level and vertical, and insert it at end of col
            }
            ans.push_back(col);
        }
        return ans;
    }
// TC: O(nlogn) -> n = queue and logn = insert (multiset)
// SC: O(n) + O(3n) -> n = map and 3n = queue
};