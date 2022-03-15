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

int len;
int num[100][100];
int ans[100][100];
int main() {
    freopen("./in", "r", stdin);
    cin >> len;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++) {
            cin >> num[i][j];
            ans[i][j] = (j == 0 ? num[i][j] : e8);
        }
    for (int j = 1; j < len; j++) {
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < len; i++) {
                int v = ans[i][j - 1];
                if (i > 0)
                    v = min(v, ans[i - 1][j]);
                if (i < len - 1)
                    v = min(v, ans[i + 1][j]);
                v += num[i][j];
                if (v < ans[i][j])
                    ans[i][j] = v, flag = true;
            }
        }
    }
    int rans = e8;
    for (int i = 0; i < len; i++) {
        rans = min(rans, ans[i][len - 1]);
    }
    cout << rans << endl;
    return 0;
}
