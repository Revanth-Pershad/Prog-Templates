#include <bits/stdc++.h>

using namespace std;

int bellman(int start, int end, int n, vector<vector<int>> &edges){
    vector<int> dist(n, INT_MAX);

    dist[start] = 0;

    for(int i = 0; i < n; i++){
        for(auto x : edges){
            int from = x[0], to = x[1], wt = x[2];
            if(dist[from] != INT_MAX)
                dist[to] = min(dist[to], dist[from] + wt);
        }
    }

    return dist[end];
}

int main(){
    int n, edges; cin >> n >> edges;
    vector<vector<int>> eds;
    while(edges--){
        int a, b, wt; cin >> a >> b >> wt;
        a--; b--;

        eds.push_back({a, b, wt});
    }

    cout << bellman(0, n-1, n, eds);
}