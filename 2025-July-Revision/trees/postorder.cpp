/*
    interative and recursive tranversal
*/

#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
};

vector<int> getPostOrder_itr(TreeNode *root){
    if(!root)return {};
    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);

    while(!st.empty()){
        auto tp = st.top(); st.pop();
        res.push_back(tp->val);

        if(tp->left)
            st.push(tp->left);

        if(tp->right)
            st.push(tp->right);
    }
    reverse(res.begin(), res.end());

    return res;
}

void dfs(TreeNode *root, vector<int> &res){
    if(!root)return;

    dfs(root->left, res);
    dfs(root->right, res);
    res.push_back(root->val);
}

vector<int> getPostorder(TreeNode *root){
    vector<int> res;

    dfs(root, res);

    return res;
}