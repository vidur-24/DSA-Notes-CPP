#include <bits/stdc++.h>
using namespace std;

// uses concept of Threaded Binary Tree
// tc = O(n) + A(n) -> A(n) is amortized time complexity
// sc = O(1) -> speciality
// last node of left subtree is connected to the root
// can be only inorder and preorder


vector<int> inorder(TreeNode* root){
    vector<int> inorder;
    
    TreeNode* curr = root;
    while (curr) {
        if (curr->left == NULL){ // if left exist
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{ // if left doesnot exist
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr){ // check for last node of left subtree (i.e, rightmmost node of left subtree)
                prev = prev->right;
            }
            if(prev->right == NULL){ // if last node is not threaded (connected to root)
                prev->right = curr; // make thread
                curr = curr->left;
            }
            else{ // if last node already threaded (means already visited left subtree)
                prev->right = nullptr; // remove thread
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return inorder;
}



vector<int> preorder(TreeNode* root){
    vector<int> preorder;

    TreeNode* curr = root;
    while (curr) {
        if (curr->left == NULL){ // if left exist
            preorder.push_back(curr->val);
            curr = curr->right;
        }
        else{ // if left doesnot exist
            TreeNode* prev = curr->left;
            while(prev->right && prev->right != curr){ // check for last node of left subtree (i.e, rightmmost node of left subtree)
                prev = prev->right;
            }
            if(prev->right == NULL){ // if last node is not threaded (connected to root)
                prev->right = curr; // make thread
                preorder.push_back(curr->val); // before moving to left print root
                curr = curr->left;
            }
            else{ // if last node already threaded (means already visited left subtree)
                prev->right = nullptr; // remove thread
                curr = curr->right;
            }
        }
    }
    return preorder;
}