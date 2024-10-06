// Check if a tree is height balanced


// We return height if the tree is balances and return -1 if it is not
class Solution {
public:
    int helper(TreeNode *root){
        if(!root)return 0;
        int lft = helper(root->left), rgt = helper(root->right);
        if(lft == -1 || rgt == -1 || abs(lft - rgt) > 1)return -1;
        return max(lft, rgt)+1;
    }

    bool isBalanced(TreeNode* root) {
        return helper(root) == -1 ? false : true;
    }
};
