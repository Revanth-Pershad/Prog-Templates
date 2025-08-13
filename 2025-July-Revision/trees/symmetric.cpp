#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:

        int val;
        TreeNode *left, *right;
};

bool dfs(TreeNode *p, TreeNode *q){
    if(!p && !q) return true;
    if(!p || !q) return false;
    if(p->val != q->val) return false;

    return dfs(p->left, q->right) && dfs(p->right, q->left);
}

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return dfs(root->left, root->right);
}
