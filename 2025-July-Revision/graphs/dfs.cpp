#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &res, vector<bool> &vis, vector<vector<int>> &graph){
    vis[node] = true;
    res.push_back(node);

    for(int x : graph[node]){
        if(!vis[x]){
            vis[x] = true;
            dfs(x, res, vis, graph);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>> &graph){
    vector<int> res;
    vector<bool> visited(n, false);

    dfs(0, res, visited, graph);

    return res;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> graph(n);

    int edges; cin >> edges;
    for(int i = 0; i < edges; i++){
        int a, b; cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    vector<int> topos = dfs(n, graph);
    for(int x : topos)
        cout << x+1 << " ";
}