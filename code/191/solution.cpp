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

const int len = 30;
long long ans[40][5][5];
int main() {
    ans[0][0][0] = 1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 1; k++) {
                ans[i + 1][j + 1][k] += ans[i][j][k];
                ans[i + 1][0][k] += ans[i][j][k];
                ans[i + 1][0][k + 1] += ans[i][j][k];
            }
        }
    }
    long long rans = 0;
    for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 1; k++) {
            rans += ans[len][j][k];
        }
    }
    cout << rans << endl;
    return 0;
}
