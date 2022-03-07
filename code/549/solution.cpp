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

int p[e8 + 1];
void init() { /*{{{*/
    p[1] = 1;
    for (int i = 2; i <= e8; i++)
        if (p[i] == 0)
            for (int j = i; j <= e8; j += i)
                p[j] = i;
} /*}}}*/
long long cnt(long long a, long long b) { /*{{{*/
    long long ret = 0;
    while (a) {
        a /= b;
        ret += a;
    }
    return ret;
} /*}}}*/
long long cal(long long a, long long b) { /*{{{*/
    // m! contains a^b
    long long lower = 1;
    long long upper = b;
    while (lower + 3 <= upper) {
        long long mid = (lower + upper) >> 1;
        if (cnt(mid, a) + mid >= b)
            upper = mid;
        else
            lower = mid;
    }
    for (long long i = lower; i <= upper; i++) {
        if (cnt(i, a) + i >= b)
            return i * a;
    }
    return -1;
} /*}}}*/
long long cal(long long a) { /*{{{*/
    map<int, int> m;
    while (a != 1) {
        m[p[a]]++;
        a /= p[a];
    }
    long long ret = 0;
    for (auto i : m) {
        ret = max(ret, cal(i.first, i.second));
    }
    return ret;
} /*}}}*/
int main() {
    init();
    long long ans = 0;
    for (int i = 1; i <= e8; i++) {
        ans += cal(i);
        if (i % e6 == 0)
            cout << i / e6 << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
