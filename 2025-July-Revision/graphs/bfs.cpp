#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, vector<vector<int>> &graph){
    vector<int> res;
    vector<bool> visited(n, false);
    
    queue<int> qu;
    qu.push(0);
    visited[0] = true;

    while(!qu.empty()){
        int node = qu.front(); qu.pop();
        res.push_back(node);

        for(int x : graph[node]){
            if(!visited[x]){
                visited[x] = true;
                qu.push(x);
            }
        }
    }

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

    vector<int> topos = bfs(n, graph);
    for(int x : topos)
        cout << x+1 << " ";
}