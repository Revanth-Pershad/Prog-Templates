// Visiting every neighbor first
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int ind){
    visited[ind] = true;
    cout << ind+1 << " "; // Correcting the padding
    // Process the current node
    for(int neighbor : graph[ind])
        if(!visited[neighbor])dfs(neighbor);
}

int main(){
    int n, edges; cin >> n >> edges;
    graph.resize(n);
    for(int i = 0; i < edges; i++){
        int a, b; cin >> a >> b;
        a--; b--; // Converting to 0-indexed
        graph[a].push_back(b); // from a->b
    }
    
    visited.resize(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i])dfs(i);
    }
}
