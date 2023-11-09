#include <iostream>/*{{{*/
long long mod = 989898989;
using namespace std; /*}}}*/
long long fac[100000], inv_fac[100000];
long long qpow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i < 100000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv_fac[100000 - 1] = qpow(fac[100000 - 1], mod - 2);
    for (int i = 100000 - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mod;
    }
}
long long C(long long a, long long b) { return fac[a] * inv_fac[b] % mod * inv_fac[a - b] % mod; }
long long F(long long n) {
    long long ans = 0;
    for (int i = 0; i <= n; i++) {                // 00
        for (int j = i & 1; i + j <= n; j += 2) { // 11
            int x = abs(i * 2 - j * 2) * 2;
            if (i + j + x > n || ((n - i - j - x) & 1))
                continue;
            x += (n - i - j - x) / 2;
            ans = (ans + C(n, i) * C(n - i, j) % mod * C(n - i - j, x) % mod) % mod;
        }
    }
    return ans;
}
int main() {
    init();
    cout << "F(2) = 4 = " << F(2) << endl;
    cout << "F(10) = 63594 = " << F(10) << endl;
    cout << "F(1000) = 199177246 = " << F(1000) << endl;
    cout << F(9898) << endl;
    return 0;
}
