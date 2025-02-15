// 0-indexed graph
void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &gp){
    vis[node] = true;
    for(int ng : gp[node])
        if(!vis[ng])
            dfs(ng, vis, st, gp);
    st.push(node);
}

void dfs2(int node, vector<bool> &vis, vector<vector<int>> &rgp, vector<vector<int>> &scc){
    vis[node] = true;
    scc[scc.size()-1].push_back(node);

    for(int ng : rgp[node])
        if(!vis[ng])
            dfs2(ng, vis, rgp, scc);
}

void solve(){
    int n, e; cin >> n >> e;
    vector<vector<int>> gp(n), rgp(n);
    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        gp[a].push_back(b);
        rgp[b].push_back(a);
    }

    vector<bool> vis(n, false);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i, vis, st, gp);
    }
    vis.assign(n, false);


    vector<vector<int>> scc;
    while(!st.empty()){
        int node = st.top(); st.pop();
        if(!vis[node]){
            scc.push_back({});
            dfs2(node, vis, rgp, scc);
        }
    }

    for(auto x : scc){
        for(auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}
