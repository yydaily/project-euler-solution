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
long long mod      = 1e9 + 7;
using namespace std; /*}}}*/

/*add{{{*/
long long base_add(long long a, long long b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
long long add(long long a, long long b) { return base_add(a, b); }
long long add(initializer_list<long long> args) {
    long long ret = 0;
    for (auto i : args)
        ret = base_add(ret, i);
    return ret;
}
/*}}}*/

/*{{{mul*/
long long base_mul(long long a, long long b) {
    a %= mod;
    b %= mod;
    long long ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ret;
}
long long mul(long long a, long long b) { return base_mul(a, b); }
long long mul(initializer_list<long long> args) {
    long long ret = 1;
    for (auto i : args)
        ret = base_mul(ret, i);
    return ret;
} /*}}}*/

/*{{{qpow*/
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul({ret, a});
        a = mul({a, a});
        b >>= 1;
    }
    return ret;
} /*}}}*/

int main() {
    long long ans1 = 0;
    long long k = 8, t = 15;
    while (true) {
        long long n = k * 2 + 1;
        long long S = n * 3 - 1;
        if (S > 1e9)
            break;
        if (S > 0) {
            ans1 += S;
            cout << n << ' ' << n << ' ' << n - 1 << endl;
        }
        long long kk = -2 * k - t - 2;
        t            = -3 * k - 2 * t - 2;
        k            = kk;
    }

    long long ans2 = 0;
    k = 2, t = 4;
    while (true) {
        long long n = k * 2 + 1;
        long long S = n * 3 + 1;
        if (S > 1e9)
            break;
        if (S > 0) {
            ans2 += S;
            cout << n << ' ' << n << ' ' << n + 1 << endl;
        }
        long long kk = -2 * k - t - 1;
        t            = -3 * k - 2 * t - 1;
        k            = kk;
    }

    cout << ans1 + ans2 << endl;
    return 0;
}
