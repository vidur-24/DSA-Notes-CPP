#include <bits/stdc++.h>
using namespace std;


// 3 steps : add root, add left boundary, add leaves, add reverse right boundary
class Solution {
    void addLeftBoundary(Node* root, vector<int> &res){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data); // if not a leaf node add to res
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    } 
    void addRightBoundary(Node* root, vector<int> &res){
        Node* cur = root->right;
        vector<int> temp; // for reversing
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data); // if not a leaf node add to temp
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            res.push_back(temp[i]);
        }
    } 
    void addLeaves(Node* root, vector<int> &res){
        if(isLeaf(root)){ // if leaf
            res.push_back(root->data);
            return;
        }
        // if not leaf
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }
public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        
        return res;
    }
// TC: O(H + N + H) -> left , leaves, right
// SC: O(H) -> right temp + ass
};