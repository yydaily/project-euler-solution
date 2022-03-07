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
vector<int> a, b;
bool check(int a) {
    ////return a == 6;
    ////return true;
    return a < 100;
}
int main() {
    for (int i = 1; i <= 20; i++) {
        a.push_back(100 + i);
        a.push_back(200 + i * 2);
        a.push_back(300 + i * 3);
        b.push_back(200 + i * 2);
    }
    a.push_back(100 + 25), a.push_back(200 + 50);
    b.push_back(200 + 50);
    int ans = 0;
    for (auto k : b)
        if (check(k % 100))
            ans++;
    cout << ans << endl;
    for (auto i : a)
        for (auto k : b)
            if (check(i % 100 + k % 100))
                ans++;
    cout << ans << endl;
    for (auto i : a)
        for (auto j : a)
            for (auto k : b)
                if (check(i % 100 + j % 100 + k % 100)) {
                    if (j < i)
                        continue;
                    ans++;
                }
    cout << ans << endl;
    return 0;
}
