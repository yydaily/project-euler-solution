#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long sqrt_5 = -1;
long long mod;
void init(long long m) {
    mod = m;
    for (long long i = 1;; i++) {
        if (i * i % m == 5) {
            sqrt_5 = i;
            break;
        }
    }
}
long long qpow(long long a, long long b) {
    a %= mod;
    a             = (a + mod) % mod;
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
long long Q(long long a, long long m) {
    init(m);
    long long pow4 = qpow(4, a);              // 16
    long long l    = qpow(1 + sqrt_5, a - 1); // 22
    long long r    = qpow(1 - sqrt_5, a - 1); // 89

    // 22 * qpow(16 - 22*22, mod-2)
    long long lret = l * qpow(pow4 - (1 + sqrt_5) * l % mod, mod - 2) % mod;
    long long rret = r * qpow(pow4 - (1 - sqrt_5) * r % mod, mod - 2) % mod;

    long long ans = ((lret - rret) % mod + mod) % mod;

    ans = (ans * 2 * qpow(sqrt_5, mod - 2)) % mod;

    return ans;
}
int main() {
    cout << Q(2, 109) << endl;
    cout << Q(3, 109) << endl;
    cout << Q(1e18, 1e9 + 9) << endl;
    return 0;
}
