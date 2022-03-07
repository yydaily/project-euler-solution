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
const long long upper = 1e16;
long long cnt[10];
long long p[10][25];
void init() { /*{{{*/
    for (int i = 1; i < 10; i++) {
        p[i][0] = 1;
        for (int j = 1; j < 25; j++) {
            p[i][j] = p[i][j - 1] * i >= upper || p[i][j - 1] < 0 ? -1 : p[i][j - 1] * i;
        }
    }
} /*}}}*/
long long cal(long long power) { /*{{{*/
    long long ret = 0;
    for (long long i = 1; i < 10; i++) {
        ret += p[i][power] * cnt[i];
        if (p[i][power] < 0 || ret >= upper)
            return -1;
    }
    return ret;
} /*}}}*/

bool check(long long a) { /*{{{*/
    if (a <= 0)
        return false;
    long long copy[10];
    for (long long i = 0; i < 10; i++)
        copy[i] = cnt[i];
    while (a) {
        copy[a % 10]--;
        a /= 10;
    }
    for (long long i = 0; i < 10; i++)
        if (copy[i] != 0)
            return false;
    return true;
} /*}}}*/

long long dfs(long long a, long long max_cnt) {
    if (a == 10) {
        long long ret = 0;
        for (long long i = 1; i <= 20; i++) {
            long long v = cal(i);
            ret += (check(v + 1) ? v + 1 : 0) + (check(v - 1) ? v - 1 : 0);
            if (ret)
                break;
        }
        return ret;
    }
    long long ans = 0;
    for (long long i = 0; i < max_cnt; i++) {
        cnt[a] = i;
        ans += dfs(a + 1, max_cnt - i);
    }
    return ans;
}

int main() {
    init();
    cout << dfs(0, 17) << endl;
    return 0;
}
