#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2  = 100;
const long long e3  = e2 * 10;
const long long e4  = e3 * 10;
const long long e5  = e4 * 10;
const long long e6  = e4 * e2;
const long long e7  = e6 * 10;
const long long e8  = e7 * 10;
const long long mod = 1e9 + 7;
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
bool p[e7];
int del(int a) { /*{{{*/
    int base = 1;
    while (base <= a)
        base *= 10;
    base /= 10;
    return a - a / base * base;
} /*}}}*/
bool check(int a) {
    int copy = a;
    while (copy) {
        if (p[copy])
            return false;
        copy /= 10;
    }
    while (a) {
        if (p[a])
            return false;
        a = del(a);
    }
    return true;
}
int main() {
    int ans = -2 - 3 - 5 - 7;
    int cnt = 0;
    p[1]    = true;
    for (int i = 2; i < e7; i++) {
        if (!p[i]) {
            for (int j = i << 1; j < e7; j += i)
                p[j] = true;
            if (check(i)) {
                cout << i << endl;
                cnt++, ans += i;
            }
            if (cnt == 15)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
