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
int upper = 12000;
map<int, int> ans;
int origin;
void add(int a, int b, int len = 0, int minm_fac = 2) {
    if (a < minm_fac)
        return;
    int copy = a;
    set<int> factor;
    factor.insert(1);
    while (copy != 1) {
        set<int> nxt;
        for (auto i : factor) {
            nxt.insert(i);
            nxt.insert(i * Prime::max_prime[copy]);
        }
        copy /= Prime::max_prime[copy];
        swap(factor, nxt);
    }
    for (auto i : factor) {
        if (i < minm_fac)
            continue;
        if (a / i < i)
            break;
        int now = len + 2 + b - i - a / i;
        if (now <= upper && ans[now] == 0)
            ans[now] = origin;
        add(a / i, b - i, len + 1, i);
    }
}
map<int, bool> vis;
int main() {
    Prime::init(5e6);
    for (int i = 2; ans.size() < upper - 1; i++) {
        origin = i;
        add(i, i);
    }
    int rans = 0;
    for (int i = 2; i <= upper; i++) {
        if (vis[ans[i]])
            continue;
        vis[ans[i]] = true;
        rans += ans[i];
    }
    cout << rans << endl;
    return 0;
}
