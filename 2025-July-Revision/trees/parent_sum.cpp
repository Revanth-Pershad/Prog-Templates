/*

*/
#include <bits/stdc++.h>

using namespace std;

class TreeNode{
    public:

        int val;
        TreeNode *left, *right;
};

void dfs1(TreeNode *root){
    if(!root)return;
    if(!root->left && !root->right)return;
    int sum = 0;

    if(root->left)sum += root->left->val;
    if(root->right)sum += root->right->val;

    if(root->val > sum){
        int diff = root->val - sum;
        if(root->left)
            root->left->val += diff;
        else 
            root->right->val += diff;
    }

    dfs1(root->left);
    dfs1(root->right);
}

int dfs2(TreeNode *root){
    if(!root)return 0;

    int left = dfs2(root->left), right = dfs2(root->right);
    root->val = left + right;

    return root->val;
}

void equate(TreeNode *root){
    // Make the parents less <= child sum
    dfs1(root);

    // Now root->val <= sum
    int temp = dfs2(root);
}

int main(){

}