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
long long _mod     = e9 + 7;
using namespace std; /*}}}*/
/*add{{{*/
long long base_add(long long a, long long b, long long mod = _mod) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
long long add(long long a, long long b, long long mod = _mod) { return base_add(a, b, mod); }
long long add(initializer_list<long long> args, long long mod = _mod) {
    long long ret = 0;
    for (auto i : args)
        ret = base_add(ret, i, mod);
    return ret;
}
/*}}}*/
/*{{{mul*/
long long base_mul(long long a, long long b, long long mod = _mod) {
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
long long mul(long long a, long long b, long long mod = _mod) { return base_mul(a, b, mod); }
long long mul(initializer_list<long long> args, long long mod = _mod) {
    long long ret = 1;
    for (auto i : args)
        ret = base_mul(ret, i, mod);
    return ret;
} /*}}}*/
/*{{{qpow*/
long long qpow(long long a, long long b, long long mod = _mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return ret;
} /*}}}*/

long long num[300];
long long cc[300];
long long mod = e8 * e8;
int main() {
    _mod   = 250;
    num[0] = 1;
    for (int i = 1; i <= 250250; i++) {
        int now = qpow(i, i);
        for (int i = 0; i < 250; i++)
            cc[i] = 0;
        for (int i = 0; i < 250; i++) {
            auto &x = cc[add(i, now)];
            x       = (x + num[i]) % mod;
        }
        for (int i = 0; i < 250; i++) {
            num[i] = (num[i] + cc[i]) % mod;
        }
    }
    cout << num[0] - 1 << endl;
    return 0;
}
