#include <bits/stdc++.h>
using namespace std;


class Solution { // recursive
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0; //BC
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + max(leftDepth, rightDepth); // 1 becuz 1 node traverse kar liya

    }
// TC : O(n)
// SC : O(H)
};

// another way : level order 
// TC : O(n)
// SC : O(n)