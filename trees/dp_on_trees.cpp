Problem - https://leetcode.com/problems/sum-of-distances-in-tree/
> First: Calculate the number of nodes in every subtree
> Second: Since 0 is not always the root we make the tree in form of a graph so that we can treat any node as the root
and travel across the tree for that node
> Third: Calculate the answer as a base case for only one node
> Fourth: Now using the answer for the root (parent) calculate the answer for all the nodes
>>> Intuition: If we know the answer for parent and we want to find the answer when the child is the root think in the following way
- Increase due to (Number of Nodes moving away from the child when it become the root) [all the nodes other that its subtree]
- Decrease due to (Number of Nodes moving toward the child when it becomes the root) [all the nodes in its subtree]
Formula = (dp[parent] + (n - subTree[node]) - (subTree[node]) {using the above logic}

class Solution {
    vector<vector<int>> gp;
    vector<int> subTree, dp;
public:
    void dfs(int node, int parent){
        subTree[node] = 1;
        dp[node] = 0;
        for(int child : gp[node]){
            if(child == parent)continue;
            dfs(child, node);
            subTree[node] += subTree[child];
            dp[node] += (dp[child] + subTree[child]);
        }
    }

    void reroot(int node, int parent, int n){
        dp[node] = dp[parent] - subTree[node] + (n - subTree[node]);
        for(int child : gp[node]){
            if(child == parent)continue;
            reroot(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        gp.resize(n);
        subTree.resize(n);
        dp.resize(n);

        for(auto edge : edges){
            gp[edge[1]].push_back(edge[0]);
            gp[edge[0]].push_back(edge[1]);
        }
        

        dfs(0, -1);
        for(int child : gp[0])
            reroot(child, 0, n);


        return dp;
    }
};
