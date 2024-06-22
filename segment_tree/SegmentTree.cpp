// Minimum in Range
class SegmentTree{
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int> &arr, int size){
        n = size;
        tree.resize(4*size + 5, INT_MAX); // Since min tree

        build(0, 0, size-1, arr);
    }

    void build(int ind, int L, int R, vector<int> &arr){
        if(L == R){
            tree[ind] = arr[L]; return;
        }
        int mid = (L + R)/2;
        build(2*ind+1, L, mid, arr);
        build(2*ind+2, mid+1, R, arr);

        tree[ind] = min(tree[2*ind+1], tree[2*ind+2]);
    }

    int query(int L, int R){
        return Query(0, L, R, 0, n-1);
    }

    int Query(int ind, int L, int R, int low, int high){
        if(R < low || L > high){
            return INT_MAX; // No Overlap
        }
        if(low >= L && high <= R){
            return tree[ind]; // Full Overlap (Query range outlooks the main range not vice versa)
        }
        int mid = (low + high)/2;
        int left = Query(2*ind+1, L, R, low, mid);
        int right = Query(2*ind+2, L, R, mid+1, high);
        return min(left, right);
    }

    void update(int pos, int val){
        Update(0, 0, n-1, pos, val);
    }

    void Update(int ind, int L, int R, int pos, int val){
        if(L == R){
            tree[ind] = val;
            return;
        }
        int mid = (L + R)/2; // Choose to go right or left
        if(pos <= mid)Update(2*ind+1, L, mid, pos, val); // Left
        else Update(2*ind+2, mid+1, R, pos, val); // Right
        tree[ind] = min(tree[2*ind+1], tree[2*ind+2]); // Update
    }

    void print(){
        for(int x : tree)if(x != -1)cout << x << " ";
    }
};

// Make sure to make the appropriate changes to the initialisation values of the segment tree.
// For min -> INT_MAX
// For sum -> 0. It doesn't actually matter but it's better to be careful.
