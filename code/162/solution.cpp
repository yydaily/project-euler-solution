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
long long cnt[2][2][2][20];
long long dfs(bool a, bool b, bool c, int need) {
    if (need == 0)
        return a && b && c;
    if (cnt[a][b][c][need])
        return cnt[a][b][c][need];
    long long ret = 0;
    for (int i = 0; i < 16; i++) {
        ret += dfs(a || i == 0, b || i == 1, c || i == 10, need - 1);
    }
    cnt[a][b][c][need] = ret;
    return ret;
}
int main() {
    long long ans = 0;
    for (int length = 1; length <= 16; length++) {
        long long buf = 0;
        buf += dfs(false, false, false, length - 1) * 13;
        buf += dfs(false, true, false, length - 1);
        buf += dfs(false, false, true, length - 1);
        cout << length << ' ' << buf << endl;
        ans += buf;
    }
    cout << setiosflags(ios::uppercase) << hex << ans << endl;
    return 0;
}
