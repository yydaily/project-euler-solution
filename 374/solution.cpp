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
const int mod = 982451653;
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

const long long query = 100;
const long long upper = 15 * e6;
long long fac[upper + 10];
long long inv[upper + 10];
void init() { /*{{{*/
    fac[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i <= upper; i++)
        fac[i] = mul(fac[i - 1], i);
    for (long long i = 2; i <= upper; i++)
        inv[i] = mul(mod - mod / i, inv[mod % i]);
} /*}}}*/
long long cal_part1() { /*{{{*/
    long long ret    = 0;
    long long length = 2;
    long long base   = 15;
    long long sum    = 8;
    for (long long i = 5; sum <= query; i++) {
        ret = add(ret, mul(length, base));
        length++;
        sum += i;
        base = mul(base, inv[i], i - 1, i + 1);
        cout << i << ' ' << ret << endl;
    }
    return ret;
} /*}}}*/
long long cal_part2() { /*{{{*/
    long long base   = 2 * 3 + 2 * 4 + 3 * 4;
    long long maxm   = 3 + 4;
    long long ret    = 0;
    long long length = 2;
    for (; maxm <= query; length++) {
        ret  = add(ret, mul(base, length));
        base = add(mul(base, length + 3), fac[length + 2]);
        maxm += (length + 3);
    }

    base = mul(fac[length + 1], length);
    for (long long nouse = (length + 1) * (length + 2) / 2 - 1; nouse <= query; nouse++) {
        ret  = add(ret, base);
        base = mul(base, length + 2, inv[length + 1]);
        length--;
    }
    return ret;
} /*}}}*/

int main() {
    init();
    long long ans = 10; // n<=4

    ans = add(ans, cal_part1(), cal_part2());

    cout << cal_part1() << ' ' << cal_part2() << ' ' << ans << endl;
    return 0;
}
