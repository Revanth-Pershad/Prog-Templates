void solve(){
    int n, e;
    cin >> n >> e;
    vvi edges(e, vector<int>(3, 0));

    for(int i = 0; i < e; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    int src = 0;
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < e; j++){

            // Like the DP question, if we reached then check
            int from = edges[j][0], to = edges[j][1], wt = edges[j][2];
            if(dist[from] != INT_MAX && dist[from] + wt < dist[to])
                dist[to] = dist[from] + wt; // Process the node here
        }
    }

    _print(dist); line;
}
