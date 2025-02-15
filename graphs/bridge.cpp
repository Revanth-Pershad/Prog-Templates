void dfs(int node, int parent, int &timer,
         vector<int> &time, vector<int> &low,
         const vector<vector<int>> &gp,
         vector<vector<int>> &bridges)
{
    time[node] = low[node] = timer++;
    
    for (int ng : gp[node]) {
        if (ng == parent) continue;
        
        if (time[ng] == -1) {
            dfs(ng, node, timer, time, low, gp, bridges);
            low[node] = min(low[node], low[ng]);
            
            // Bridge condition (can be reached from some other parent's ancestor)
            // Thus can't be a bridge if <
            if (low[ng] > time[node]) {
                bridges.push_back({node, ng});
            }
        } else {
            // If visited and not parent, minimize low[node]
            // Cannot be a bridge because since this is visited it was visited 
            // From some other edge and not from (node -> ng) thus (node -> ng) 
            // is not a bridge
            low[node] = min(low[node], time[ng]);
        }
    }
}

vector<vector<int>> getBridges(int n, const vector<vector<int>> &gp){
    vector<int> time(n, -1), low(n, -1);
    vector<vector<int>> bridges;
    int timer = 0;
    
    // Loop for Connected Components
    for (int i = 0; i < n; i++) {
        if (time[i] == -1) {
            dfs(i, -1, timer, time, low, gp, bridges);
        }
    }
    return bridges;
}

void solve(){
    int n, e; cin >> n >> e;
    vector<vector<int>> gp(n);

    for(int i = 0; i < e; i++){
        int a, b; cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    auto bridges = getBridges(n, gp);

    for(auto &edge : bridges){
        cout << edge[0] << " " << edge[1] << "\n";
    }
}
