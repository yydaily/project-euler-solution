#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = 1e9 + 7;
using namespace std; /*}}}*/

/*{{{qpow*/
long long qpow(long long a, long long b, long long mod = _mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
} /*}}}*/

const long long e18 = e9 * e9;
long long m[e4];    // C_18^9 % p = m[p]
long long fac[e4];  // fac[i] = i!%p
long long ifac[e4]; // ifac[i] = (1/i!) % p
long long lucas(long long n, long long m, long long p) {
    if (n == 0 && m == 0)
        return 1;
    auto a = n % p, b = m % p;
    if (a < b)
        return 0;
    return fac[a] * ifac[b] % p * ifac[a - b] % p * lucas(n / p, m / p, p) % p;
}
long long cal(long long p1, long long p2, long long p3) {
    long long ret1 = qpow(p2 * p3, p1 - 2, p1) * p2 * p3 * m[p1];
    long long ret2 = qpow(p1 * p3, p2 - 2, p2) * p1 * p3 * m[p2];
    long long ret3 = qpow(p1 * p2, p3 - 2, p3) * p1 * p2 * m[p3];
    return (ret1 + ret2 + ret3) % (p1 * p2 * p3);
}
bool is_prime(int a) {
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}
int main() {
    vector<int> prime;
    for (int i = 1000; i < 5000; i++)
        if (is_prime(i))
            prime.push_back(i);
    for (auto p : prime) { /*{{{*/
        if (p < 1000)
            continue;
        fac[0] = 1;
        for (int i = 1; i < p; i++)
            fac[i] = fac[i - 1] * i % p;
        ifac[p - 1] = qpow(fac[p - 1], p - 2, p);
        for (int i = p - 2; i >= 0; i--)
            ifac[i] = ifac[i + 1] * (i + 1) % p;
        m[p] = lucas(e18, e9, p);
    } /*}}}*/
    long long ans = 0;
    for (int i = 0; i < prime.size(); i++) {
        for (int j = i + 1; j < prime.size(); j++) {
            for (int k = j + 1; k < prime.size(); k++) {
                if (!m[prime[i]] && !m[prime[j]] && !m[prime[k]])
                    continue;
                auto v = cal(prime[i], prime[j], prime[k]);
                ans += v;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
