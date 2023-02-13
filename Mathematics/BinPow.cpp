ll BinPow(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Other Option
long long modPow(long long a, long long b, long long mod){
    if(b==0) return 1;
    if(b%2==0){
        long long x = modPow(a, b/2, mod);
        return (x*x)%mod;
    }
    else return (a*modPow(a, b-1, mod))%mod;
}