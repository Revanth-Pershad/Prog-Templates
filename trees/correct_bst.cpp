// Inorder of a BST is a strictly increasing array
class Solution {
public:
    vector<int> inorder(TreeNode *root){
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while(curr || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            auto tp = st.top(); st.pop();
            res.push_back(tp->val);
            curr = tp->right;
        }
        return res;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> ino = inorder(root);
        for(int i = 1; i < ino.size(); i++)
            if(ino[i] <= ino[i-1])return false;
        return true;
    }
};
