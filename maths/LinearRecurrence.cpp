class LinearRecurrence {
    int k; // Number of dependents
    vector<vector<long long>> initials; // f(0), f(1), ... f(k)
    vector<vector<long long>> constants; // a, b, c ... k

    const int MOD = 1000000007;

public:
    LinearRecurrence(vector<long long> &init, vector<long long> &cons, int n) {
        k = n;
        for (auto x : init) initials.push_back({x});

        constants.resize(k, vector<long long>(k, 0));
        for (int i = 0; i < k; ++i) constants[0][i] = cons[i];
        for (int i = 1; i < k; ++i)
            for (int j = 0; j < k; ++j)
                if (i == j + 1) constants[i][j] = 1;
    }

    // Matrix Multiplication
    vector<vector<long long>> matMul(vector<vector<long long>> &a, vector<vector<long long>> &b) {
        long long arow = a.size(), acol = a[0].size(), bcol = b[0].size();
        vector<vector<long long>> res(arow, vector<long long>(bcol, 0ll));

        for (long long i = 0; i < arow; ++i) {
            for (long long j = 0; j < bcol; ++j) {
                for (long long k = 0; k < acol; ++k) {
                    res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
                }
            }
        }

        return res;
    }

    // Matrix Exponentiation
    vector<vector<long long>> power(vector<vector<long long>> mat, long long n) {
        long long size = mat.size();
        vector<vector<long long>> res(size, vector<long long>(size, 0ll));
        for (long long i = 0; i < size; ++i)
            res[i][i] = 1; // Identity matrix

        while (n > 0) {
            if (n % 2 == 1)
                res = matMul(res, mat);
            mat = matMul(mat, mat);
            n /= 2;
        }

        return res;
    }

    long long findN(int n) {
        if (n < k) return initials[n][0];
        vector<vector<long long>> mid = power(constants, n);
        vector<vector<long long>> result = matMul(mid, initials);
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
