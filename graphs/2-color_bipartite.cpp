// Check if the graph can be divided into two groups
// ie bipartite

vvi graph;
vi colors; // Color of each node

bool dfs(int ind, bool clr){
    colors[ind] = clr;
    for(int neighbor : graph[ind]){
        if(colors[neighbor] == colors[ind])return false;
        if(colors[neighbor] == -1) // If not colored
            if(!dfs(neighbor, !clr))return false; // If cannot color return false
    }
    return true;
}

bool color(int n){
    rep(i, n)   // If there are multiple components
        if(colors[i] == -1)
            if(!dfs(i, 0))return false;

    return true;
}

void solve(){
    int n, edges; cin >> n >> edges;
    graph.resize(n);
    colors.resize(n, -1); // '-1' no color
    rep(i, edges){
        int a, b; cin >> a >> b;
        a--; b--; // 0-indexed
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bool isPossible = color(n);
    if(isPossible)
        for(int x : colors)
            cout << (x+1) << " "; // Since 0 indexed
    else cout << "IMPOSSIBLE";
}
