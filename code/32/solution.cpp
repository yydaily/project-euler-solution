#include "../template/bigint.cpp"
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

int num[10];
void add(int a) {
    while (a) {
        num[a % 10]++;
        a /= 10;
    }
}
bool check(int a, int b, int c) {
    memset(num, 0, sizeof(num));
    add(a), add(b), add(c);
    if (num[0])
        return false;
    for (int i = 1; i < 10; i++)
        if (num[i] != 1)
            return false;
    return true;
}
map<int, bool> m;
int main() {
    for (int i = 1; i < e6; i++) {
        for (int j = i + 1; i * j < e6; j++) {
            if (check(i, j, i * j)) {
                m[i * j] = true;
            }
        }
    }
    int ans = 0;
    for (auto i : m) {
        ans += i.first;
    }
    cout << ans << endl;
    return 0;
}
