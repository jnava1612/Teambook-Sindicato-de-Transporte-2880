//O(nlogn)

//To improve efficiency, the factorial inverse of n is calculated and the rest of the inverses are found by multiplying by n-i, so that the binomial coefficients are found in O(1) time.

int pot (int b, int e) {
    int res = 1;
    while(e)
    {
        if(e & 1) res = res * b % MOD;
        b = b * b % MOD;
        e /= 2;
    }
    return res;
}
vi fac(tam), facin(tam);
int bino(int n, int k) {
    return k < 0 ? 0 : n < 0 ? 0 : k > n ? 0 : fac[n] * facin[k] % MOD * facin[n - k] % MOD;
};
void precalbino() {
    fac[0] = facin[0] = 1;
    fore(i, 1, tam)
    {
        fac[i] = fac[i - 1] * i % MOD;
        facin[i] = pot(fac[i], MOD - 2);
    }
}