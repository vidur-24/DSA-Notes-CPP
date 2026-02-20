#include <bits/stdc++.h>
using namespace std;


class Solution { // strivers
    TreeNode* solve(vector<int>& pre, int preStart, int preEnd, vector<int>& in, int inStart, int inEnd, map<int, int> &inMap){
        if(preStart > preEnd || inStart > inEnd){ // bc
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[preStart]);

        int inRoot = inMap[root->val]; // idx of root in inorder
        int numsLeft = inRoot - inStart;
        
        root->left = solve(pre, preStart+1, preStart+numsLeft, in, inStart, inRoot-1, inMap);
        root->right = solve(pre, preStart+numsLeft+1, preEnd, in, inRoot+1, inEnd, inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        map<int, int> inMap; // val-idx map for inorder
        for(int i=0; i<n; i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, 0, n-1, inorder, 0, n-1, inMap);
        return root;
    }
// tc = sc = O(n)
};




class Solution { // love babbar
    TreeNode* solve(int n, vector<int>& pre, vector<int>& in, int& preIdx, int inStart, int inEnd){
        // BC
        if(preIdx >= n || inStart > inEnd){
            return NULL;
        }

        // processing
        int val = pre[preIdx++]; // root node val
        TreeNode* root = new TreeNode(val);
        // finding pos of root val in 'in'
        auto itr = find(in.begin(), in.end(), val);
        int pos = itr - in.begin();

        // RR
        root->left = solve(n, pre, in, preIdx, inStart, pos-1);
        root->right = solve(n, pre, in, preIdx, pos+1, inEnd);

        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIndex = 0;
        TreeNode* root = solve(n, preorder, inorder, preIndex, 0, n-1);
        return root;
    }
};