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
long long cnt(long long lower, long long upper) { /*{{{*/ // 返回 lower! * (lower+1)! * ... * upper! 中有多少个 2
    long long ret = 0;
    for (long long base = 2;; base <<= 1) {
        long long l = lower / base;
        long long r = upper / base;
        if (r == 0)
            break;
        if (l == r) {
            ret += (upper - lower + 1) * l;
            continue;
        }
        ret += (l * base + base - lower) * l;
        l++;

        ret += (upper - r * base + 1) * r;
        r--;

        if (r >= l) {
            ret += (r * (r + 1) / 2 - l * (l - 1) / 2) * base;
        }
    }
    return ret;
} /*}}}*/
const long long upper = 1e16;
int main() {
    // 1 2 | 3 4 5 6 | 7 8 9 10
    // 1 1 | 1 1 2 3 | 1 1 2 3
    // 0 1 | 2 3 3 3 | 6 7 7 7
    long long l      = 0;
    long long length = 2;
    long long ans    = 0;
    while (l < upper) {
        long long r = min(upper, l + length);
        ans += cnt(l + 1, r) - cnt(1, r - l - 1) - cnt(l, l) - cnt(l + 1, l + 1) * (r - l - 1);
        length <<= 1;
        l = r;
    }
    cout << ans << endl;
    return 0;
}
