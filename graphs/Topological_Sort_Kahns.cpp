vvi gp;
void kahns(vvi &edges, int n){
    // Create Graph and Calculate inOrder
    gp.resize(n);
    vi inOrder(n, 0);
    for(auto edge : edges){
        gp[edge[0]].pb(edge[1]);
        inOrder[edge[1]]++;
    }

    queue<int> qu;
    rep(i, n)
        if(inOrder[i] == 0)qu.push(i);

    // Start the Kahn's
    while(!qu.empty()){
        int ind = qu.front(); qu.pop();

        // Process the node
        cout << ind << " ";

        for(int neighbor : gp[ind]){
            inOrder[neighbor]--;
            if(inOrder[neighbor] == 0)qu.push(neighbor);
        }
    }
}

/* Works only on DAG (true for every topological sort)
Create a graph 
Add all the initial ancestors with 0 inorder edges to the queue
Process the nodes in the queue 
reduce the inorder of the neighbors as if removing the current node
if the inorder reaches 0 for a node add it to the queue
this way all the nodes will be processed */

void solve(){
    int n, k; cin  >> n >> k;
    vvi edges;
    rep(i, k){
        int a, b; cin >> a >> b;
        edges.pb({a, b});
    }

    kahns(edges, n);
}


// WHEN GRAPH IT SELF IS GIVEN INSTEAD OF EDGES
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


    while(!qu.empty()){
        int node = qu.front(); qu.pop();
        cout << node;

        for(int ngh : graph[node]){
            inOrder[ngh]--;
            if(inOrder[ngh] == 0)qu.push(ngh);
        }
    }
}
