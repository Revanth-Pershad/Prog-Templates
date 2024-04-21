// Union By Size
class UnionFind{
    vector<int> parent, size;
    public:
        UnionFind(int n){
            parent.resize(n);
            for(int i = 0; i < n; i++)parent[i] = i;
            size.resize(n, 1);
        }

        int findParent(int n){
            if(parent[n] == n)return n;
            return parent[n] = findParent(parent[n]); // Path Compression
        }

        void insert(int u, int v){
            int parentU = findParent(u), parentV = findParent(v);
            if(parentU == parentV)return;

            if(size[parentU] > size[parentV]){
                parent[parentV] = parentU;
                size[parentU] += size[parentV];
            }else{
                parent[parentU] = parentV;
                size[parentV] += size[parentU];
            }
        }

        bool sameStruct(int u, int v){
            return findParent(u) == findParent(v);
        }
};

// Union By Rank
class UnionFind{
    vector<int> parent, rank;
    public:
        UnionFind(int n){
            parent.resize(n);
            for(int i = 0; i < n; i++)parent[i] = i;
            rank.resize(n, 1);
        }

        int findParent(int n){
            if(parent[n] == n)return n;
            return parent[n] = findParent(parent[n]); // Path Compression
        }

        void insert(int u, int v){
            int parentU = findParent(u), parentV = findParent(v);
            if(parentU == parentV)return;

            if(rank[parentU] > rank[parentV])parent[parentV] = parentU;
            else if(rank[parentV] > rank[parentU])parent[parentU] = parent[parentV];
            else{
                parent[parentV] = parentU;
                rank[parentU]++;
            }
        }

        bool sameStruct(int u, int v){
            return findParent(u) == findParent(v);
        }
};
