#include <bits/stdc++.h>
using namespace std;
long long u   = 1000000;
long long mod = 1e9 + 7;
long long add(long long a, long long b) { /*{{{*/
    a = (a + b) % mod;
    return (a + mod) % mod;
} /*}}}*/
long long mul(long long a, long long b) { /*{{{*/
    a = a * b % mod;
    return (a + mod) % mod;
} /*}}}*/
long long qpow(long long a, long long b) { /*{{{*/
    a %= mod;
    a             = (a + mod) % mod;
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
} /*}}}*/
long long cal(long long a) {
    // return a^1 + ... + a^(1e6)
    long long ret = a;
    ret           = mul(ret, qpow(1 - a, mod - 2));
    ret           = mul(ret, add(0, 1 - qpow(a, u)));
    return ret;
}
int main() {
    // u = 1e6
    // ans = \sum_{i=1}^u \sum_{j=1}^u (1-i^2)^j
    long long ans = 0;
    for (long long i = 1; i <= u; i++)
        ans = add(ans, cal(add(0, 1 - i * i)));
    cout << ans << endl;
    return 0;
}
