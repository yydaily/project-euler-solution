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
int rad(int a) {
    int ret = 1;
    while (a != 1) {
        int p = Prime::max_prime[a];
        ret *= p;
        while (a % p == 0)
            a /= p;
    }
    return ret;
}
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
const int upper = 120000;
long long rrad[e6];
int main() {
    Prime::init(2 * e5);
    for (int c = 1; c < 2 * e5; c++)
        rrad[c] = rad(c);
    long long ans = 0;
    for (int c = 1; c < upper; c++) {
        if (rrad[c] == c)
            continue;
        long long now = c / rrad[c];
        for (int a = 1; a < c / 2; a++) {
            if (rrad[a] >= now || rrad[a] * rrad[c - a] >= now)
                continue;
            if (gcd(a, c) != 1)
                continue;
            cout << a << ' ' << c - a << ' ' << c << endl;
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}
