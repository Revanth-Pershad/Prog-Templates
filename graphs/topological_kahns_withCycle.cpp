void solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    int edges; cin >> edges;

    while(edges--){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> inOrder(n, 0);
    queue<int> qu;
    for(int i = 0; i < n; i++){
        for(int ngh : graph[i])inOrder[ngh]++;
    }

    for(int i = 0; i < n; i++)
        if(inOrder[i] == 0)qu.push(i);

    int cnt = 0;
    while(!qu.empty()){
        int node = qu.front(); qu.pop();
        cout << node; // Process the node
        cnt++;

        for(int ngh : graph[node]){
            inOrder[ngh]--;
            if(inOrder[ngh] == 0)qu.push(ngh);
        }
    }

    if(cnt != n)cout << "Found a cycle"; // Meaning we did not visit all nodes because of a cycle
}
