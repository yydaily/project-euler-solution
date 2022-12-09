#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
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
inline long long add(long long a, long long b) { return (a + b) % _mod; }
inline long long mul(long long a, long long b) { return a * b % _mod; }
inline long long qpow(long long a, long long b) {
    b %= _mod - 1;
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
long long fac[e7 + 10];
long long inv_fac[e7 + 10];
void init() {
    fac[0] = 1;
    for (long long i = 1; i <= e7; i++)
        fac[i] = mul(fac[i - 1], i); // fac[i] = (fac[i-1]*i)%_mod;
    inv_fac[e7] = qpow(fac[e7], _mod - 2);
    for (long long i = e7 - 1; i >= 0; i--)
        inv_fac[i] = mul(inv_fac[i + 1], i + 1);
}
long long C(long long a, long long b) { return mul(fac[a], mul(inv_fac[b], inv_fac[a - b])); }
long long pow_sum(long long i, long long m) {
    // return 1 + i + ... + i^m = (i^{m+1}-1) / (i-1)
    return mul(add(qpow(i, m + 1), _mod - 1), qpow(i - 1, _mod - 2));
}
long long I(long long a, long long n) {
    long long ret  = 0;
    long long flag = 1;
    for (long long i = a - 1; i >= 0; i--) {
        if (i == 1)
            ret += flag * mul(a, (n + 1) % _mod);
        else if (i == 0)
            ret += flag;
        else
            ret += mul(_mod + flag, mul(C(a, i), pow_sum(i, n)));
        flag = -flag;
    }
    return ret % _mod;
}
int main() {
    init();
    cout << I(3, 0) << endl;
    cout << I(3, 2) << endl;
    cout << I(3, 4) << endl;
    cout << I(e7, e6 * e6) << endl;
    return 0;
}
