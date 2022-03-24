#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/pell.cpp"
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
int fac(int a) {
    if (a <= 1)
        return 1;
    return fac(a - 1) * a;
}
int c(int a, int b) { return fac(a) / fac(b) / fac(a - b); }
int cal(int a) {
    vector<int> v;
    for (int i = 0; i < a - 1; i++)
        v.push_back(i >= a / 2 ? 1 : 0);
    int ret = 0;
    do {
        vector<int> l, r;
        for (int i = 0; i < a - 1; i++) {
            if (v[i])
                r.push_back(i);
            else
                l.push_back(i);
        }
        for (int i = 0; i < (a / 2) - 1; i++) {
            if (l[i] > r[i]) {
                for (auto i : l)
                    cout << i << ' ';
                cout << ":";
                for (auto i : r)
                    cout << i << ' ';
                cout << a - 1 << endl;
                ret++;
                break;
            }
        }
    } while (next_permutation(v.begin(), v.end()));
    return ret;
}
const int len = 12;
int main() {
    int ans = 0;
    for (int i = 4; i <= len; i += 2) {
        ans += c(len, i) * cal(i);
    }
    cout << ans << endl;
    return 0;
}
