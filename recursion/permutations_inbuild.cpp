void solve(){
    int n; cin >> n;
    vi arr(n); _scan(arr);
    sortall(arr);

    do{
        _print(arr);
        line;
    }while(next_permutation(all(arr)));
}
