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

long long add(long long a, long long b) { return (a + b) % _mod; }
long long mul(long long a, long long b) { return a * b % _mod; }
long long qpow(long long a, long long b) { /*{{{*/
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
} /*}}}*/
int fac[e4], inv[e4];
void init() {
    fac[0] = 1;
    for (int i = 1; i < e4; i++)
        fac[i] = mul(fac[i - 1], i);
    inv[e4 - 1] = qpow(fac[e4 - 1], _mod - 2);
    for (int i = e4 - 2; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}
long long cnt(long long need, long long length) {
    if (need > length)
        return 0;
    long long ret = mul(fac[length], inv[need]);
    ret           = mul(ret, inv[length - need]);
    return mul(ret, qpow(9, length - need));
}
int length = 2022;
int main() {
    init();
    long long ans = 0;
    for (int i = 1; i <= length; i++) {
        for (int need = i / 2 + 1; need <= i; need++) {
            ans = add(ans, mul(cnt(need, i - 1), 9));
            ans = add(ans, cnt(need - 1, i - 1));
        }
    }
    cout << mul(ans, 9) << endl;
    return 0;
}
