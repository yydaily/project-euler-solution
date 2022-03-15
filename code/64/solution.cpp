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
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
map<string, int> m;
int gen(int &a, int &b, int &c, int &d) { /*{{{*/
    int aa = a * d;
    int cc = -d * c;
    int dd = a * a * b - c * c;
    int g  = gcd(aa, gcd(cc, dd));
    aa /= g, cc /= g, dd /= g;
    int x = (aa * sqrt(b) + cc) / dd;
    cc -= dd * x;
    a = aa;
    c = cc;
    d = dd;
    return x;
} /*}}}*/
int len(int i, int j) {
    int a = 1, b = i, c = -j, d = 1;
    int ind = 0;
    while (true) {
        int v  = gen(a, b, c, d);
        auto s = to_string(a) + ' ' + to_string(b) + ' ' + to_string(c) + ' ' + to_string(d) + ' ' + to_string(v);
        if (m[s])
            return ind - m[s];
        m[s] = ind++;
    }
    return -1;
}
int main() {
    int ans = 0;
    for (int i = 2; i <= 10000; i++) {
        int j = sqrt(i);
        if (j * j == i)
            continue;
        cout << i << ' ' << len(i, j) << endl;
        if (len(i, j) & 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
