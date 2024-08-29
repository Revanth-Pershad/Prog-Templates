vi arr, used;

void generate(vi &perm){
    if(perm.size() == arr.size()){
        _print(perm); line; return;
    }

    rep(i, arr.size()){
        if(used[i])continue;
        used[i] = true;
        perm.pb(arr[i]);
        generate(perm);
        used[i] = false;
        perm.pop_back();
    }
}

void solve(){
    int n; cin >> n;
    arr.resize(n); _scan(arr);
    used.resize(n, false);
    vi perm;

    generate(perm);
}
