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
const int mod = 1e9 + 87;
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

bool p[e7 + 10];
int l[e7 + 10]; // 对i来说最小的prime
int cnt[e7 + 10];
int inv[4 * e7 + 10];
void init() {
    inv[1]    = 1;
    int e7__2 = e7 << 2;
    for (int i = 2; i <= e7__2; i++) {
        inv[i] = mul(mod - mod / i, inv[mod % i]);
    }
    for (int i = 2; i <= e7; i++)
        if (!p[i]) {
            for (int j = i; j <= e7; j += i) {
                l[j] = i;
                p[j] = true;
            }
        }
    cout << "init success" << endl;
}
int base = 1;
int cal(int a) {
    while (a != 1) {
        int x = add(1, mul(2, cnt[l[a]]));
        base  = mul(base, inv[x]);
        base  = mul(base, add(1, mul(2, cnt[l[a]]), 2));
        cnt[l[a]]++;
        a /= l[a];
    }
    return base;
}
int main() {
    init();
    int ans = 0;
    for (int i = 2; i <= e7; i++)
        ans = add(ans, cal(i));
    cout << ans << endl;
    return 0;
}
