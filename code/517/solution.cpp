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
long long mod      = e9 + 7;
using namespace std; /*}}}*/

long long add(long long a, long long b) {
    a += b;
    return a >= mod ? a - mod : a;
}
long long mul(long long a, long long b) { return a * b % mod; }
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
const long long upper = e7 + e6;
long long fac[upper], inv[upper];
void init() {
    fac[0] = 1;
    for (long long i = 1; i < upper; i++)
        fac[i] = mul(fac[i - 1], i);
    inv[upper - 1] = qpow(fac[upper - 1], mod - 2);
    for (long long i = upper - 2; i >= 0; i--)
        inv[i] = mul(inv[i + 1], i + 1);
}
long long C(int a, int b) { return mul(fac[a], mul(inv[b], inv[a - b])); }

long long G(long long a) {
    long double x = sqrt(a);
    long long ans = 0;
    for (int i = 0; i * x < a; i++) {
        int j = a - i * x;
        ans   = add(ans, C(i + j, i));
    }
    return ans;
}

int main() {
    init();
    cout << G(90) << endl;
    long long ans = 0;
    for (int i = 10000001; i < 10010000; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            ans = add(ans, G(i));
    }
    cout << ans << endl;
    return 0;
}
