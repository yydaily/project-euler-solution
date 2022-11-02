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
long long mod     = 1475789056;
long long phi_mod = 632481024;
long long qpow(long long base, long long upper, long long m) {
    long long ret = 1;
    while (upper) {
        if (upper & 1)
            ret = ret * base % m;
        base = base * base % m;
        upper >>= 1;
    }
    return ret;
}
long long cal(long long m, long long n) {
    if (m == 0)
        return n + 1;
    if (m == 1)
        return n + 2;
    if (m == 2)
        return n * 2 + 3;
    if (m == 3)
        return pow(2, n + 3) - 3;
    if (m == 4) {
        if (n == 0)
            return 13;
        if (n >= 7)
            return 829575165;
        long long now = 4;
        while (n--)
            now = qpow(2, now % phi_mod + phi_mod, phi_mod);
        return qpow(2, now % phi_mod + phi_mod, mod) - 3;
    }
    if (m == 5) {
        if (n == 0)
            return 65533;
        else
            return 829575165;
    }
    return 829575165;
}

int main() {
    // 利用欧拉降幂可以发现，数列快速收敛
    long long ans = 0;
    for (int i = 0; i <= 6; i++)
        ans = (ans + cal(i, i)) % mod;
    cout << ans << endl;
    return 0;
}
