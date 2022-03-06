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
long long mod      = e8 * e8;
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

long long mod_length = 16;
long long length     = 2020;
long long cnt[10][3000];
long long dfs2(int remain, int total_len) { /*{{{*/
    if (cnt[remain][total_len]) {
        return cnt[remain][total_len];
    }
    if (total_len == 1)
        return 1;
    long long ret = 0;
    for (int i = 0; i <= remain; i++) {
        ret = add(ret, dfs2(remain - i, total_len - 1));
    }
    cnt[remain][total_len] = ret;
    return ret;
} /*}}}*/
long long cal(int remain, int max_digit) { /*{{{*/
    long long total_len = length - mod_length;
    long long ret       = 1;
    if (max_digit)
        ret = total_len--;
    ret = mul(ret, dfs2(remain, total_len));
    return ret;
} /*}}}*/
long long dfs(int len, int remain, int max_digit, long long now = 0) { /*{{{*/
    now %= mod;
    if (remain == 0 && max_digit == 0) {
        for (int i = len; i < mod_length; i++)
            now = mul(now, 10);
        return now;
    }
    if (len == mod_length) {
        return mul(now, cal(remain, max_digit));
    }
    long long ans = 0;
    if (max_digit)
        ans = add(ans, dfs(len + 1, remain, 0, now * 10 + max_digit));
    for (int i = 0; i <= remain; i++) {
        if (remain == max_digit && i == remain)
            continue;
        ans = add(ans, dfs(len + 1, remain - i, max_digit, now * 10 + i));
    }
    return ans;
} /*}}}*/

int main() {
    long long ans = 0;
    for (int max_digit = 1; max_digit <= 9; max_digit++) {
        cout << max_digit << endl;
        ans = add(ans, dfs(0, max_digit, max_digit));
    }
    cout << ans << endl;
    return 0;
}
