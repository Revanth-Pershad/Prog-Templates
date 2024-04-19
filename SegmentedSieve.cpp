class Sieve {
    int mx;
    vector<bool> sieve;

public:
    Sieve(int n) : mx(n), sieve(n + 1, true) {
        initializeSieve();
    }

    void initializeSieve() {
        sieve[0] = sieve[1] = false;  // 0 and 1 are not primes
        for (int i = 2; i * i <= mx; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    vector<int> getPrimes() {
        vector<int> primes;
        for (int i = 2; i <= mx; ++i)
            if (sieve[i]) primes.push_back(i);
        return primes;
    }
};

class SegmentedSieve {
    int low, high;
    vector<bool> segment;

public:
    SegmentedSieve(int l, int h) : low(l), high(h), segment(h - l + 1, true) {
        Sieve s(sqrt(high));
        vector<int> primes = s.getPrimes();
        initializeSegment(primes);
    }

    void initializeSegment(const vector<int>& primes) {
        for (int prime : primes) {
            int start = max(prime * prime, ((low + prime - 1) / prime) * prime);
            for (int j = start; j <= high; j += prime) {
                segment[j - low] = false;
            }
        }
        if (low == 1) segment[0] = false;  // Mark 1 as non-prime explicitly if in range
    }

    void printPrimes() {
        for (int i = 0; i < segment.size(); i++)
            if (segment[i]) cout << (low + i) << "\n";
    }
};
