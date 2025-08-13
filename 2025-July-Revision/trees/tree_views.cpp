#include <bits/stdc++.h>

using namespace std;

/*
    top, bottom, left, right
*/

class Node{
    public:
        int data;
        Node *left, *right;
};

class TreeNode{
    public:
        int val;
        Node *left, *right;
};

vector<int> topView(Node *root){
    map<int, int> mp;
    vector<int> res;


    queue<pair<Node*, int>> qu;
    qu.push({root, 0});

    while(!qu.empty()){
        auto node = qu.front().first;
        int num = qu.front().second;
        qu.pop();

        if(mp.find(num) == mp.end())
            mp[num] = node->data;

        if(node->left)
            qu.push({node->left, num-1});
        
        if(node->right)
            qu.push({node->right, num+1});
    }

    for(auto x : mp)
        res.push_back(x.second);
    return res;
}

vector<int> rightView(TreeNode *root){
    if(!root)return {};
    vector<int> res;

    queue<pair<TreeNode *, int>> qu;
    qu.push({root, 1});

    while(!qu.empty()){
        auto node = qu.front().first; int val = qu.front().second;
        qu.pop();

        if(val > res.size())
            res.push_back(node->val);

        if(node->right)
            qu.push({node->right, val+1});

        if(node->left)
            qu.push({node->left, val+1});
    }

    return res;
}

vector<int> leftView(TreeNode *root){
    if(!root)return {};
    vector<int> res;

    queue<pair<TreeNode *, int>> qu;
    qu.push({root, 1});

    while(!qu.empty()){
        auto node = qu.front().first; int val = qu.front().second;
        qu.pop();

        if(val > res.size())
            res.push_back(node->val);

        if(node->left)
            qu.push({node->left, val+1});

        if(node->right)
            qu.push({node->right, val+1});
    }

    return res;
}

vector<int> bottomView(Node *root){
    if(!root)return {};
    map<int, int> mp;


    queue<pair<Node *, int>> qu;
    qu.push({root, 0});

    while(!qu.empty()){
        auto node = qu.front().first; int val = qu.front().second;
        mp[val] = node->data;

        if(node->left)
            qu.push({node->left, val-1});
            
        if(node->right)
            qu.push({node->right, val+1});
    }

    vector<int> res;
    for(auto x : mp)
        res.push_back(x.second);

    return res;
}

int main(){
    
}