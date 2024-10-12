class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v){
        val = v;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode *root, int val){
    if(!root)return new TreeNode(val);
    if(val > root->val)root->right = insert(root->right, val);
    else root->left = insert(root->left, val);
    return root;
}

TreeNode* minVal(TreeNode *root){
    TreeNode* temp = root;
    while(temp->left)
        temp = temp->left;
    return temp;
}

TreeNode* del(TreeNode *root, int val){
    if(!root)return root;
    if(val > root->val)root->right = del(root->right, val);
    else if(val < root->val)root->left = del(root->left, val);
    else{
        // No Child
        if(!root->left && !root->right)return NULL;

        // One Child
        else if(!root->right || !root->left){
            if(!root->right)return root->left;
            else return root->right;
        }
        // Two Child
        else{
            // Replace with inOrder Successor
            TreeNode* succ = minVal(root->right);
            root->val = succ->val;
            root->right = del(root->right, root->val);
        }
    }
}

void inOrder(TreeNode *root){
    if(!root)return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void solve(){
    TreeNode *root = NULL;
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 6);

    inOrder(root); line;

    root = del(root, 2);
    root = del(root, 6);

    inOrder(root);
}
