// 0-indexed graph (we are correcting a 1-indexed graph)
// Directed Graph

bool check(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inCycle) {
    visited[node] = true;
    inCycle[node] = true;
    
    for (int neigh : graph[node]) {
        if (inCycle[neigh]) return true;
        else if (!visited[neigh]) {
            if (check(neigh, graph, visited, inCycle)) return true;
        }
    }
    
    inCycle[node] = false;
    return false;
}

bool hasCycle(vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false), inCycle(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
        if (!visited[i]) {
            if (check(i, graph, visited, inCycle)) return true;
        }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }
    
    if (hasCycle(graph))
        cout << "There is a Cycle";
    else
        cout << "There is no Cycle";
    
    return 0;
}
