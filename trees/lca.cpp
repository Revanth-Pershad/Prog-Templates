// We know that both p and q exist so at somepoint at the lca both lft and rgt exist thus
// that is when we send the current node and after which only one of them is not NULL
// because we already found the LCA thus we send the root getting the answer
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)return root;
        auto lft = lowestCommonAncestor(root->left, p, q), rgt =  lowestCommonAncestor(root->right, p, q);
        if(!rgt)return lft;
        if(!lft)return rgt;
        return root;
    }
};
