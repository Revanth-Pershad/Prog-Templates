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

