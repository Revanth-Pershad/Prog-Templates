class Sieve{
    int mx;
    vector<bool> siev;

    public:
    Sieve(int n){
        mx = n;
        siev.resize(n, true);
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
};
