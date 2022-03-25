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
    vector<long long> v;
    long long k = 0, L = 1;
    for (int i = 0; i < 14; i++) {
        auto kk = -9 * k - 4 * L - 4;
        L       = -20 * k - 9 * L - 8;
        k       = kk;
        cout << k * 2 << ' ' << L << endl;
        if (L > 0)
            v.push_back(L);
    }
    cout << endl << endl;

    k = 0, L = -1;
    for (int i = 0; i < 14; i++) {
        auto kk = -9 * k - 4 * L + 4;
        L       = -20 * k - 9 * L + 8;
        k       = kk;
        cout << k * 2 << ' ' << L << endl;
        if (L > 0)
            v.push_back(L);
    }
    cout << endl << endl;

    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < 12; i++) {
        cout << v[i] << endl;
        ans += v[i];
    }
    cout << ans << endl;
    return 0;
}
