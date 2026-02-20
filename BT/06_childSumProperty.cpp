#include <bits/stdc++.h>
using namespace std;


// Given an arbitrary binary tree, your task is to convert it to a binary tree that holds Children Sum Property, by incrementing the data values of any node.
// Note: The structure of the tree can't be changed and the node values can't be decremented. Also, there exist multiple possible answers.


class Solution {
    void changeTree(TreeNode* root) {
        if(!root) return;

        int childSum = 0;
        if(root->left) childSum += root->left->val;
        if(root->right) childSum += root->right->val;

        if(childSum >= root->val) { // update current node
            root->val = childSum;
        } else { // update children nodes, so they are at least equal to current node and not less (cuz cant decrement)
            if(root->left) root->left->val = root->val;
            if(root->right) root->right->val = root->val;
        }

        changeTree(root->left);
        changeTree(root->right);

        int tot = 0;
        if(root->left) tot += root->left->val;
        if(root->right) tot += root->right->val;
        if(root->left || root->right) { // if not a leaf node
            root->val = tot; // update current node to the sum of its children
        }
// tc : O(n)
// sC : O(H)
};
