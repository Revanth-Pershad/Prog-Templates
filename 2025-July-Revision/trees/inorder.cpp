/*
    both the recursive and interative traversal
*/

#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
};

void dfs(TreeNode *root, vector<int> &res){
    if(!root)return;
    dfs(root->left, res);
    res.push_back(root->val);
    dfs(root->right, res);
}

vector<int> getInorder(TreeNode *root){
    vector<int> res;
    dfs(root, res);
    return res;
}


vector<int> getInorder_Itr(TreeNode *root){
    if(!root)return {};

    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }

        auto tp = st.top(); st.pop();
        res.push_back(tp->val);
        curr = tp->right;
    }
    
    return res;
}