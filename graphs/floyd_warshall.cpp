// Remember with different k we carry the set of the intermediate node
// k = 0 {0}
// k = 1 {0, 1}
// k = 2 {0, 1, 2}
// ...

// This means at k = n we consider all the intermediate paths including {0, 1, 2, ... n-1}

const ll INF = 1e16;

void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vll> gp(n, vll(n, INF));

    rep(i, m){
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;
        gp[a][b] = min(gp[a][b], c); // Multiple same paths with different weights
        gp[b][a] = min(gp[b][a], c);
    }

    for(int i = 0; i < n; i++)
        gp[i][i] = 0;

    // Floydd Warshall
    for(int k = 0; k < n; k++){
        vector<vll> temp(n, vll(n, INF));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = min(gp[i][j], gp[i][k] + gp[k][j]);
            }
        }

        gp = temp;
    }

    while(q--){
        int a, b; cin >> a >> b;
        a--; b--;

        cout << (gp[a][b] == INF ? -1 : gp[a][b]);
        line;
    }
}
