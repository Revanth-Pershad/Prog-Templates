#include <bits/stdc++.h>

using namespace std;

vector<int> topo_sort(int n, vector<vector<int>> &graph){
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        for(int x : graph[i])
            indegree[x]++;
    }

    queue<int> qu;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0){
            qu.push(i);
        }

    vector<int> res;
    while(!qu.empty()){
        int node = qu.front(); qu.pop();
        res.push_back(node);

        for(int x : graph[node]){
            indegree[x]--;

            if(indegree[x] == 0)
                qu.push(x);
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

    vector<int> topos = topo_sort(n, graph);
    for(int x : topos)
        cout << x+1 << " ";
}