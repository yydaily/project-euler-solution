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

vector<long long> gen(vector<long long> v) { /*{{{*/
    if (v.size() <= 2) {
        v.push_back(v[v.size() - 1] * 2 - v[0]);
        return v;
    }
    vector<long long> diff;
    for (int i = 1; i < v.size(); i++)
        diff.push_back(v[i] - v[i - 1]);
    diff = gen(diff);
    v.push_back(v[v.size() - 1] + diff[diff.size() - 1]);
    return v;
} /*}}}*/
long long cal(long long a) {
    long long ans  = 1;
    long long base = 1;
    for (int i = 1; i <= 10; i++) {
        base *= -a;
        ans += base;
    }
    return ans;
}
int main() {
    long long ans = 0;
    vector<long long> v;
    for (int i = 1;; i++) {
        long long now = cal(i);
        v.push_back(now);
        auto diff = gen(v);
        if (diff[diff.size() - 1] == cal(i + 1))
            break;
        cout << diff[diff.size() - 1] << ' ' << cal(i + 1) << endl;
        ans += diff[diff.size() - 1];
    }
    cout << ans << endl;
    return 0;
}
