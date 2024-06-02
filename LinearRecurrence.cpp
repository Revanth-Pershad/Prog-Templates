class LinearRecurrence {
    int k; // Number of dependents
    vvll initials; // f(0), f(1), ... f(k)
    vvll constants; // a, b, c ... k

public:
    LinearRecurrence(vll &init, vll &cons, int n) {
        k = n;
        for (auto x : init) initials.push_back({x});

        constants.resize(k, vll(k, 0));
        for (int i = 0; i < k; ++i) constants[0][i] = cons[i];
        for (int i = 1; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (i == j + 1) constants[i][j] = 1;
    }

    // Matrix Multiplication
    vvll matMul(vvll &a, vvll &b) {
        ll arow = a.size(), acol = a[0].size(), bcol = b[0].size();
        vvll res(arow, vll(bcol, 0ll));

        for (ll i = 0; i < arow; ++i) {
            for (ll j = 0; j < bcol; ++j) {
                for (ll k = 0; k < acol; ++k) {
                    res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                }
            }
        }

        return res;
    }

    // Matrix Exponentiation
    vvll power(vvll mat, ll n) {
        ll size = mat.size();
        vvll res(size, vll(size, 0ll));
        for (ll i = 0; i < size; ++i)
            res[i][i] = 1; // Identity matrix

        while (n > 0) {
            if (n % 2 == 1)
                res = matMul(res, mat);
            mat = matMul(mat, mat);
            n /= 2;
        }

        return res;
    }

    ll findN(ll n) {
        if (n < k) return initials[n][0];
        vvll mid = power(constants, n);
        vvll result = matMul(mid, initials);
        return result[0][0];
    }
};

// Example of Fibonacci Series
void solve() {
    ll n;
    cin >> n;
    vll initials = {0, 1}; // Initial values for Fibonacci sequence
    vll constants = {1, 1}; // Coefficients for Fibonacci sequence
    LinearRecurrence lr(initials, constants, 2);

    cout << lr.findN(n) << endl;
}
