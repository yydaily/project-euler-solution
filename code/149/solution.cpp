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
long long mod      = 1000000;
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

long long nouse[e6 * 4 + 1];
int num[2010][2010];
long long ans[4][2010][2010];
int main() {
    for (long long i = 1; i <= e6 * 4; i++) {
        if (i <= 55)
            num[(i - 1) / 2000 + 1][(i - 1) % 2000 + 1] = nouse[i] = (100003 - 200003 * i + 300007 * i * i * i) % mod - 500000;
        else
            num[(i - 1) / 2000 + 1][(i - 1) % 2000 + 1] = nouse[i] = (nouse[i - 24] + nouse[i - 55] + 1000000) % mod - 500000;
    }
    long long rans = 0;
    for (int i = 1; i <= 2000; i++) {
        for (int j = 1; j <= 2000; j++) {
            ans[0][i][j] = max(ans[0][i - 1][j], 0LL) + num[i][j];
            ans[1][i][j] = max(ans[1][i][j - 1], 0LL) + num[i][j];
            ans[2][i][j] = max(ans[2][i - 1][j - 1], 0LL) + num[i][j];
            rans         = max(max(rans, ans[0][i][j]), max(ans[1][i][j], ans[2][i][j]));
        }
        for (int j = 2000; j >= 1; j--) {
            ans[3][i][j] = max(ans[3][i - 1][j + 1], 0LL) + num[i][j];
            rans         = max(rans, ans[3][i][j]);
        }
    }
    cout << rans << endl;
    return 0;
}
