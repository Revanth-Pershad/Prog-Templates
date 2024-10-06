// Morris Trversal
// This traversal uses the concept of Binary Threaded Tree.

// InOrder
    // Recursive

    void helper(TreeNode *root){
        if(!root)return NULL;
        helper(root->left);
        cout << root->val << " ";
        helper(root->right);
    }

    // Iterative
    // Intuition - We only go left for inner while loop and we only go right for 
    // outer while loop thus not entering a infinite loop
    vector<int> inOrder(TreeNode *root){
        vector<int> res;
        TreeNode *curr = root;
        stack<TreeNode *> st;

        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            auto tp = st.top(); st.pop();
            res.push_back(tp->val);
            curr = tp->right;
        }

        return res;
    }

    // Morris
    void helper(TreeNode *root){

    }

// PreOrder
    // Recursive
    void preOrder(TreeNode *root){
        if(!root)return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    // Iterative
    vector<int> preOrder(TreeNode *root){
        if(!root)return {};
        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            auto tp = st.top(); st.pop();
            res.push_back(tp->val);

            if(tp->right)st.push(tp->right);
            if(tp->left)st.push(tp->left);
        }
        return res;
    }

    // Morris 
    vector<int> helper(TreeNode *root){
        vector<int> res;

        return res;
    }


// PostOrder
    // Recursive
    void postOrder(TreeNode *root){
        if(!root)return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    // Iterative O(2 * N)
    vector<int> postOrder(TreeNode *root){
        if(!root)return {};

        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);

        while(!st.empty()){
            auto tp = st.top(); st.pop();
            res.push_back(tp->val);

            if(tp->left)st.push(tp->left);
            if(tp->right)st.push(tp->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
