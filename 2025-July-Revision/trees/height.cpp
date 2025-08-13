#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:

        int val;
        TreeNode *left, *right;
};


int height(TreeNode *root){
    if(!root)return 0;

    int left = 0, right = 0;
    if(root->left)
        left = height(root->left);

    if(root->right)
        right = height(root->right);

    return max(left, right) + 1;
}