#include <bits/stdc++.h>

using namespace std;

class Dsu{
    vector<int> size, parent;
public:
    Dsu(int n){
        size.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int getParent(int a){
        if(a == parent[a])return a;
        return parent[a] = getParent(parent[a]);
    }

    void connect(int a, int b){
        int pa = getParent(a), pb = getParent(b);
        if(pa == pb)return;

        if(size[pa] > size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
    }
};

int kruskals(int n, vector<vector<int>> &edges){
    int total = 0;
    Dsu *ds = new Dsu(n);

    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    });

    for(auto x : edges){
        int from = x[0], to = x[1], wt = x[2];
        from--; to--;

        if(ds->getParent(from) != ds->getParent(to)){
            total += wt;
            ds->connect(from, to);
        }
    }

    return total;
}

int main(){
    int n, edge;
    cin >> n >> edge;
    vector<vector<int>> edges;
    while(edge--){
        int a, b, wt;
        cin >> a >> b >> wt;

        edges.push_back({a, b, wt});
    }
    cout << kruskals(n, edges);
}