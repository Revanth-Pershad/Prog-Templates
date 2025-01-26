class DSU {
    int n;
    vector<int> parent, sz;

public:
    DSU(int n) {
        this->n = n;
        sz.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int getParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = getParent(parent[node]); // Path compression
    }

    void merge(int u, int v) {
        int pu = getParent(u), pv = getParent(v);
        if (pu == pv) return; // Already in the same component

        if (sz[pu] >= sz[pv]) {
            parent[pv] = pu;   // Attach smaller tree under larger tree
            sz[pu] += sz[pv];
        } else {
            parent[pu] = pv;
            sz[pv] += sz[pu];
        }
    }
};

void solve() {
    int n, edges;
    cin >> n >> edges;
    vector<pair<int, pair<int, int>>> arr(edges);

    for (int i = 0; i < edges; i++) {
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first; // u - v - wt
    }

    sort(arr.begin(), arr.end()); // Sort edges by weight
    DSU ds = DSU(n);

    int total = 0;
    for (int i = 0; i < edges; i++) {
        int wt = arr[i].first, a = arr[i].second.first, b = arr[i].second.second;
        int pa = ds.getParent(a), pb = ds.getParent(b);

        if (pa != pb) {
            ds.merge(a, b); // Add the edge to the MST
            total += wt;
        }
    }

    cout << "Total Weight of the MST - " << total << "\n";
}
