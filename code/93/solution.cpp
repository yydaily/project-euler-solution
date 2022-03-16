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

vector<double> gen(vector<int> v) {
    vector<double> ret;
    if (v.size() == 1) {
        ret.push_back(v[0]);
        return ret;
    }
    for (int i = 0; i < v.size(); i++) {
        vector<int> buf;
        for (int j = 0; j < v.size(); j++) {
            if (j == i)
                continue;
            buf.push_back(v[j]);
        }
        auto now = gen(buf);
        for (auto j : now) {
            ret.push_back(v[i] + j);
            ret.push_back(v[i] * j);

            ret.push_back(v[i] - j);
            ret.push_back(j - v[i]);
            ret.push_back(v[i] / j);
            ret.push_back(j / v[i]);
        }
    }
    return ret;
}
int cal(vector<double> x) {
    map<int, bool> m;
    for (auto i : x) {
        int j = i;
        if (i == j)
            m[j] = true;
    }
    for (int i = 1;; i++) {
        if (!m[i])
            return i - 1;
    }
}
int main() {
    int ans = 0;
    for (int i = 1; i <= 20; i++) {
        for (int j = i + 1; j <= 20; j++) {
            for (int k = j + 1; k <= 20; k++) {
                for (int l = k + 1; l <= 20; l++) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    v.push_back(l);
                    int now = cal(gen(v));
                    if (now > ans) {
                        ans = now;
                        cout << i << j << k << l << endl;
                    }
                }
            }
        }
    }
    return 0;
}
