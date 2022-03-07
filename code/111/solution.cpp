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
const int upper = 10;
const int e9    = e4 * e5;
int num[upper];
long long cal(long long a, long long b) {
    memset(num, -1, sizeof(num));
    for (int i = upper - 1; i >= upper - b; i--)
        num[i] = a;
    long long ret = 0;
    do {
        for (long long add = 1;; add++) {
            long long now  = 0;
            long long copy = add;
            for (int i = 0; i < upper; i++) {
                if (num[i] != -1)
                    now = now * 10 + num[i];
                else {
                    now = now * 10 + copy % 10;
                    copy /= 10;
                }
            }
            if (copy)
                break;
            if (now / e9 == 0)
                continue;
            if (Prime::is_prime(now))
                ret += now;
        }
    } while (next_permutation(num, num + upper));
    return ret;
}
int main() {
    Prime::init(e5);
    long long ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = upper; j >= 1; j--) {
            long long v = cal(i, j);
            if (v) {
                cout << i << ' ' << j << ' ' << v << endl;
                ans += v;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
