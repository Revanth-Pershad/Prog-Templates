// This is the greedy version we try to choose the least weight among the connecting nodes to the unconnected nodes
#include <bits/stdc++.h>

using namespace std;
int prims(int n, vector<vector<pair<int, int>>> &graph){
    int total = 0;
    vector<int> vis(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({0, 0});

    while(!qu.empty()){
        int node = qu.top().second, val = qu.top().first;
        qu.pop();

        if(vis[node])continue;
        vis[node] = true;
        total += val;

        for(auto x : graph[node]){
            if(!vis[x.second])
                qu.push({x});
        }
    }

    return total;
}

int main(){
    int n, edges;
    cin >> n >> edges;

    vector<vector<pair<int, int>>> graph(n);
    while(edges--){
        int a, b, wt; cin >> a >> b >> wt;
        a--; b--;

        graph[a].push_back({wt, b});
        graph[b].push_back({wt, a});
    }

    cout << prims(n, graph);
}