#include "../template/bigint.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const int e2  = 100;
const int e3  = e2 * 10;
const int e4  = e3 * 10;
const int e5  = e4 * 10;
const int e6  = e4 * e2;
const int e7  = e6 * 10;
const int e8  = e7 * 10;
const int mod = 1e9 + 7;
using namespace std; /*}}}*/

/*add{{{*/
template <typename T> T base_add(T a, T b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
template <typename T> T add(const T &t) { return t; }
template <typename T, typename... Args> T add(const T &t, const Args &...args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T> T base_mul(T a, T b) {
    a %= mod;
    b %= mod;
    T ret(0);
    while (b) {
        if (b & 1)
            ret = (ret + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ret;
}
template <typename T> T mul(const T &t) { return t; }
template <typename T, typename... Args> T mul(const T &t, const Args &...args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T> T qpow(T a, T b) {
    T ret(1);
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
/*}}}*/

long long c[21][41];
long long cal(long long a, long long b) {
    if (a > b)
        return 0;
    if (a == b || a == 0)
        return 1;
    if (c[a][b])
        return c[a][b];
    c[a][b] = cal(a - 1, b - 1) + cal(a, b - 1);
    return c[a][b];
}
int main() {
    cout << cal(2, 4) << endl;
    cout << cal(20, 40) << endl;
    return 0;
}
