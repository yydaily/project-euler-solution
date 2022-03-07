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
    return (a * b) % mod;
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

const int upper = 20000;
int num[upper];
vector<int> c[upper + 1];
int inv[upper + 1];
int sub[upper + 1];
void init() { /*{{{*/
    inv[1] = 1;
    for (int i = 2; i <= upper; i++)
        inv[i] = qpow(i, mod - 2);
    for (int i = 2; i <= upper; i++) {
        int now = i;
        for (int j = 2; j * j <= now; j++) {
            while (now % j == 0) {
                c[i].push_back(j);
                now /= j;
            }
        }
        if (now > 1)
            c[i].push_back(now);
    }
} /*}}}*/
int cal(int a) {
    for (auto j : c[a]) {
        sub[j]--;
        num[j] += a;
    }
    for (int i = 2; i <= a; i++)
        num[i] += sub[i];
    int ret = 1;
    for (int i = 2; i <= a; i++) {
        if (num[i] == 0)
            continue;
        ret = mul(ret, inv[i - 1]);
        ret = mul(ret, qpow(i, num[i] + 1) - 1);
    }
    return ret;
}
int main() {
    init();
    long long ans = 0;
    for (int i = 1; i <= upper; i++) {
        cout << i << endl;
        ans = add(ans, cal(i));
    }
    cout << ans << endl;
    return 0;
}
