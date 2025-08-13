#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:

        int val;
        TreeNode *left, *right;
};

int dfs(int &mx, TreeNode *root){
    if(!root)return 0;
    int left = dfs(mx, root->left);
    int right = dfs(mx, root->right);

    mx = max(mx, left + right + 1);
    return max(left, right) + 1;
}

int diameter(TreeNode *root){
    int mx = 0;
    int temp = dfs(mx, root);
    return mx;
}