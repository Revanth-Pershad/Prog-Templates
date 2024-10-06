// Finding the height of the left and the right and then adding them gives the correct value for the diameter of the tree
class Solution {
    int mx = 0;
public:
    int height(TreeNode *root){
        if(!root)return NULL;
        int lft = height(root->left), rgt = height(root->right);
        mx = max(lft + rgt + 1, mx);
        return max(lft, rgt)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ht = height(root);
        return mx-1; // Since points between two points
    }
};
