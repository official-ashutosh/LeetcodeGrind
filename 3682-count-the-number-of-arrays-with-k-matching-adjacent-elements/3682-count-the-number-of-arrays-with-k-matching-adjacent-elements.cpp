const int N = 1e6;
const int M = 1e9 + 7;
const int MX = sqrt(N) + 5;
const long long MAXN = 1e5;
const long long MOD = 1e9 + 7;

long long fac[MAXN + 1];
long long inv[MAXN + 1];


int binexp(int a, int b, int m){
    a %= m;
    int result = 1;
    while(b > 0){
        if(b & 1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return result;
}

int divMod(long long a, long long b, int m){
    return ((a % m) * (binexp(b, m-2, m)) % m) % m;
}

long long exp(long long x, long long n, long long m) {
    x %= m;
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

void factorial() {
    fac[0] = 1;
    for (long long i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for (long long i = MAXN - 1; i >= 0; i--) { inv[i] = inv[i + 1] * (i + 1) % MOD; }
}

long long choose(long long n, long long r) { 
    if(r>n)return 0ll;
    return (fac[n] * inv[r] % MOD * inv[n - r] % MOD)%MOD;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        factorial();

        long long ans = ((choose(n-1, k) * m % MOD) * (binexp(m-1, n-k-1, MOD))) % MOD;

        return ans;
    }
};