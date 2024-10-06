// Find the maximum of the left and right and then add 1 for the current root node and this is the height of the current subtree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int lft = maxDepth(root->left), rgt = maxDepth(root->right);
        return max(lft, rgt)+1;
    }
};
