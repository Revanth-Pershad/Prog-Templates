#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &st, vector<vector<int>> &graph){
    visited[node] = true;
    for(int x : graph[node])
        if(!visited[x])
            dfs(x, visited, st, graph);
    st.push(node);
}

vector<int> topo_dfs(vector<vector<int>> &graph){
    stack<int> st;
    vector<bool> visited(graph.size(), false);
    for(int i = 0; i < graph.size(); i++)
        if(!visited[i])
            dfs(i, visited, st, graph);

    vector<int> res;
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main(){
    int n, edges; cin >> n >> edges;
    vector<vector<int>> graph(n);
    while(edges--){
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
    }

    vector<int> topo = topo_dfs(graph);
    for(int x : topo)
        cout << x+1 << " ";
}