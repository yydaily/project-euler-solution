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
int num[9];
void check(int len) {
    bool flag = true;
    for (int i = 0; i < len; i++) {
        if (num[i] == -1)
            flag = false;
    }
    if (flag)
        return; // no unknown item

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 0 && num[0] == -1)
            continue; // 0 can't be start
        int now = 0;
        for (int j = 0; j < len; j++) {
            now = now * 10 + (num[j] == -1 ? i : num[j]);
        }
        if (Prime::is_prime(now))
            cnt++;
    }
    if (cnt == 8) {
        for (int i = 0; i < 10; i++) {
            if (i == 0 && num[0] == -1)
                continue; // 0 can't be start
            int now = 0;
            for (int j = 0; j < len; j++) {
                now = now * 10 + (num[j] == -1 ? i : num[j]);
            }
            if (Prime::is_prime(now)) {
                cout << now << endl;
                exit(0);
            }
        }
    }
}
int main() {
    Prime::init(e7);
    for (int len = 2; len < 9; len++) {
        for (int j = 0; j < 9; j++)
            num[j] = -1;
        do {
            int ind = 0;
            num[ind]++;
            if (num[0] == 0)
                num[0] = 1;
            while (num[ind] > 9) {
                num[ind] = -1;
                num[++ind]++;
            }
            check(len);
        } while (num[len] == -1);
    }
    return 0;
}
