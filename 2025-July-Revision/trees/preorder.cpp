/*
    Both the interative and recursive
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
    res.push_back(root->val);
    dfs(root->left, res);
    dfs(root->right, res);
}

vector<int> getPreorder(TreeNode *root){
    vector<int> res;
    dfs(root, res);
    return res;
}

vector<int> getPreorder_itr(TreeNode *root){
    if(!root)return {};
    vector<int> res;
    
    stack<TreeNode *> st;
    st.push(root);

    while(!st.empty()){
        auto temp = st.top(); st.pop();
        res.push_back(temp->val);

        if(temp->right)
            st.push(temp->right);

        if(temp->left)
            st.push(temp->left);
    }

    return res;
}