// Can be used to check for a condition in all the subsets iteratively

void solve(){
    int n; cin >> n;
    vi arr(n); _scan(arr);

    vvi res;
    for(int i = 0; i < (1<<n); i++){
        vi temp;
        for(int bit = 0; bit < n; bit++){
            // Check if the bit is toggled
            if(i & (1 << bit)) temp.pb(arr[bit]);
        }
        res.pb(temp);
    }

    for(auto x : res){
        _print(x); line;
    }
}
