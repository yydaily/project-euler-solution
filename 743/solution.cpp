#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2  = 100;
const long long e3  = e2 * 10;
const long long e4  = e3 * 10;
const long long e5  = e4 * 10;
const long long e6  = e4 * e2;
const long long e7  = e6 * 10;
const long long e8  = e7 * 10;
const long long mod = 1e9 + 7;
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
    return a * b % mod;
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
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
} /*}}}*/

const long long total_len = 1e16;
const long long sub_len   = 1e8;
const long long Round     = total_len / sub_len;

long long start;
int main() {
    long long inv  = qpow(qpow(2, 2 * Round), mod - 2);
    long long base = qpow(2, total_len);
    cout << 0 << ' ' << base << endl;
    long long ans = base;
    for (long long i = 1; (i << 1) <= sub_len; i++) { // how much 11/00
        if (i % (sub_len / 200) == 0) {
            cout << i * 200 / sub_len << endl;
        }
        long long inv_i = qpow(i, mod - 2);
        base            = mul({base, sub_len - 2 * i + 1, sub_len - 2 * i + 2, inv_i, inv_i, inv});
        // cout<<i<<' '<<base<<endl;
        ans = add(ans, base);
    }
    cout << ans << endl;
    return 0;
}
