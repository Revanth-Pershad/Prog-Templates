// Undirected Graph Approach
void solve() {
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> gp(n);
    for (int i = 0; i < e; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        gp[a].push_back({wt, b});
        gp[b].push_back({wt, a});
    }

    vector<int> dist(n, INT_MAX);
    int src = 0;
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [currWt, node] = pq.top();
        pq.pop();

        if (currWt > dist[node]) continue; // Avoid processing outdated distances

        for (auto &[edgeWt, neighbor] : gp[node]) {
            int newDist = currWt + edgeWt;
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                pq.push({newDist, neighbor});
            }
        }
    }

    cout << (dist[n - 1] == INT_MAX ? -1 : dist[n - 1]);  // Handle unreachable nodes
}
