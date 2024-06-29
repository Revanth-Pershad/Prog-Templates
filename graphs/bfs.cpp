/* The queue can hold structures or classes to carry extra information */

vvi gp;
void bfs(int start){
    int n = gp.size();
    vb visited(n, false);
    queue<int> qu;
    qu.push(start);
    while(!qu.empty()){
        int ind = qu.front(); qu.pop();
        visited[ind] = false;

        // Process the node
        cout << ind << " ";

        for(int neighbor : gp[ind])
            if(!visited[neighbor])qu.push(neighbor);
    }
}

void solve(){
    int n, k; cin >> n >> k; 
    gp.resize(n);
    rep(i, k){
        int a, b; cin >> a >> b;
        gp[a].pb(b);
    }

    bfs(0);
}
