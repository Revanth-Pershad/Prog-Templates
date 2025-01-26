void solve() {
    int n; 
    cin >> n; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);
    int edges; 
    cin >> edges; // Number of edges

    while (edges--) {
        int a, b, wt; 
        cin >> a >> b >> wt;
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt}); // Undirected graph
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // {weight, node}
    int total = 0;

    while (!pq.empty()) {
        int currNode = pq.top().second;
        int currWeight = pq.top().first;
        pq.pop();

        if (visited[currNode]) continue;
        visited[currNode] = true;
        total += currWeight;

        for (auto &neighbor : graph[currNode]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            if (!visited[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }

    cout << total << "\n"; // Output the total weight of MST
}
