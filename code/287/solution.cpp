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
const int N           = 24;
const long long limit = 1LL << (2 * N - 2);
bool check(long long x, long long y) {
    // return true if black; otherwise false
    long long xx = x - (1 << (N - 1));
    long long yy = y - (1 << (N - 1));
    return xx * xx + yy * yy <= limit;
}
int dfs(long long x, long long y, long long length) {
    if (length == 1)
        return 2;
    long long xx = x + length - 1, yy = y + length - 1, sub_len = length >> 1;
    int cnt = 0;
    if (check(x, y))
        cnt++;
    if (check(xx, y))
        cnt++;
    if (check(x, yy))
        cnt++;
    if (check(xx, yy))
        cnt++;
    if (check(x + sub_len - 1, y + sub_len - 1))
        cnt++;

    if (cnt == 5 || cnt == 0)
        return 2;
    return 1 + dfs(x, y + sub_len, sub_len) + dfs(x + sub_len, y + sub_len, sub_len) + dfs(x, y, sub_len) + dfs(x + sub_len, y, sub_len);
}
int main() {
    cout << dfs(0, 0, 1 << N) << endl;
    return 0;
}
