// We recheck the path of the dfs to make sure that we are not in a loop

bool dfs(int node, vector<vector<int>> &graph, stack<int> &st, vector<bool> &visited, vector<bool> &path){
    visited[node] = true;
    path[node] = true;

    for(int ngh : graph[node]){
        if(path[ngh])return true;
        else if(dfs(ngh, graph, st, visited, path))return true;
    }
    st.push(node);
    path[node] = false;
    return false;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    int edges; cin >> edges;

    while(edges--){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    stack<int> st;
    vector<bool> visited(n, false), path(n, false);

    for(int node = 0; node < n; node++)
        if(!visited[node])
            if(dfs(node, graph, st, visited, path)){
                cout << "There is cycle in the graph\n";
                return;
            }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}
