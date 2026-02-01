#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// 1. Preorder
class Solution { // recursive
public:
    vector<int> preorder(TreeNode* root) {
        vector<int> v;
        if(root != NULL){ //BC
            v.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
        return v;
    }
// TC: O(n)
// SC: O(H) = O(n) for recursion stack
};

class Solution { // iterative
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();

            v.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) st.push(root->left);
        }

        return v;
    }
// TC: O(n)
// SC: O(n) = O(H) for stack
};



// 2. Inorder
class Solution { // recursive
public:
    vector<int> preorder(TreeNode* root) {
        vector<int> v;
        if(root != NULL){ //BC
            preorder(root->left);
            v.push_back(root->val);
            preorder(root->right);
        }
        return v;
    }
// TC: O(n)
// SC: O(H) = O(n) for stack
};

class Solution { // iterative
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;

        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;

                node = st.top();
                st.pop();
                v.push_back(node->val);
                node = node->right;
            }
        }

        return v;
    }
// TC: O(n)
// SC: O(H) = O(n) for stack
};



// 3. Postorder
class Solution { // recursive
public:
    vector<int> preorder(TreeNode* root) {
        vector<int> v;
        if(root != NULL){ //BC
            preorder(root->left);
            preorder(root->right);
            v.push_back(root->val);
        }
        return v;
    }
// TC: O(n)
// SC: O(H) = O(n) for recursion stack
};

class Solution { // iterative : similar to preorder
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(!root) return v;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();

            v.push_back(root->val);
            if(root->left != NULL) st.push(root->left);
            if(root->right != NULL) st.push(root->right);
        }

        reverse(v.begin(), v.end()); // tc : O(n)
        return v;
    }
// TC: O(2n)
// SC: O(n) = O(H) for stack
};
// or instead of reverse, we can use a second stack to store the result in reverse order and then push it to the vector 
// tc: O(n)
// sc: O(2n)
// also, we have another method using single stack, check strivers
// tc: O(2n)
// sc: O(n)




// 4. Level Order
class Solution { // without using NULL marker
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue <TreeNode*> q;
        q.push(root); // Level 0

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                
                level.push_back(node->val);
            }
            
            ans.push_back(level);
        }
        return ans;
    }
// TC: O(n)
// SC: O(n) for queue
};

class Solution { // using NULL marker
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        vector<int> in;
        
        //BC
        if(!root){ // empty ke liye memory exceed aa raha
            return out;
        }
        
        queue <TreeNode*> q;
        // Level 0
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){ // NULL aa gaya that means 1 level khatam ho gayi
                out.push_back(in); // prev level ko push kardo in 'out' vector
                in.erase(in.begin(), in.end()); // 'in' vector ko clear kar do
                if(!q.empty()){  // jo level insert ki uske child elements insert karne ke baad, then insert NULL at end to show end of next level
                    q.push(NULL);
                }
            }
            else{ 
                in.push_back(temp->val); // curr level ke elements insert kardo 'in' vector mein
                // now child elements queue mein daal do
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return out;
    }
};





// Pre - In - Post in a single traversal
class Solution {
public:
    void order(TreeNode* root) {
        vector<int> pre, in, post;

        if(!root) return;

        stack<pair<TreeNode*, int>> st; // {node, state} (1: pre, 2: in, 3: post)
        st.push({root, 1});

        while(!st.empty()){
            auto it = st.top();
            st.pop();

            // pre
            // ++
            // left
            if(it.second == 1){ // pre-order
                pre.push_back(it.first->val);
                it.second++; // increment state to in-order
                st.push(it); // push
                
                if(it.first->left) {
                    st.push({it.first->left, 1}); // push left child with pre-order state
                }
            }

            // in
            // ++
            // right
            else if(it.second == 2){ // in-order
                in.push_back(it.first->val);
                it.second++; // increment state to post-order
                st.push(it); // push
                
                if(it.first->right) {
                    st.push({it.first->right, 1}); // push right child with pre-order state
                }
            }

            else{
                post.push_back(it.first->val); // post-order
            }
    }
// TC: O(3n)
// SC: O(H) + O(3n) = O(4n)
};