#include <bits/stdc++.h>

using namespace std;

class DSU{
    vector<int> size, parent;
public:

    DSU(int n){
        size.resize(n, 0);
        parent.resize(n, -1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int getParent(int a){
        if(parent[a] == a)return a;
        return parent[a] = getParent(parent[a]);
    }

    void connect(int a, int b){
        int pa = getParent(a), pb = getParent(b);
        if(pa == pb)return;

        if(size[pa] > size[pb]){
            size[pa] += size[pb];
            parent[pb] = pa;
        }else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
    }
};

int main(){
    // int n; cin >> n;
    // vector<vector<int>> graph(n);

    // int edges; cin >> edges;ṇ
    // for(int i = 0; i < edges; i++){
    //     int a, b; cin >> a >> b;
    //     a--; b--;

    //     graph[a].push_back(b);
    // }

    // vector<int> topos = bfs(n, graph);
    // for(int x : topos)
    //     cout << x+1 << " ";

    DSU *ds = new DSU(5);
    ds->connect(1, 2);
    ds->connect(3, 4);

    if(ds->getParent(2) == ds->getParent(4))
        cout << "We messed up";
    
    if(ds->getParent(4) == ds->getParent(3))
        cout << "Everything looks good!";
}