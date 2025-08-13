#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
};

bool dfs(TreeNode *root, int node, vector<int> &res){
    if(!root)return false;
    if(root->val == node){
        res.push_back(root->val);
        return true;
    }

    if(dfs(root->left, node, res) || dfs(root->right, node, res)){
        res.push_back(root->val);
        return true;
    }
    return false;
}

vector<int> path(TreeNode *root, int node){
    vector<int> res;
    bool found = dfs(root, node, res);

    reverse(res.begin(), res.end());

    return res;
}