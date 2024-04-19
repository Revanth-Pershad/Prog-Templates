class Sieve{
    int mx;
    vector<bool> siev;

    public:
    Sieve(int n){
        mx = n+1;
        siev.resize(n+1, true);
        intialiseSieve();
    }

    void intialiseSieve(){
        siev[0] = siev[1] = false;
        for(int i = 2; i * i <= mx; i++){
            for(int j = i + i; j <= i*i; j += i){
                siev[j] = false;
            }
        }
    }

    bool isPrime(int n){
        return siev[n];
    }

    vector<int> getPrimes(int n){
        vector<int> res;
        for(int i = 2; i * i <= n; i++)
            if(siev[i])res.push_back(i);
        return res;
    }
};

Sieve sieve = Sieve(1e6);
