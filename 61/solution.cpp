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
vector<int> num;
void gen(int add, int ind) { /*{{{*/
    int base = 1;
    int now  = 1;
    while (now < e4) {
        base += add;
        now += base;
        if (now >= e3)
            num.push_back(now * 10 + ind);
    }
} /*}}}*/
int vis[6];
int start;
void dfs(int ind, int last = -1) {
    // cout<<"dfs("<<ind<<", "<<last<<")"<<endl;
    if (ind == 6 && vis[start] / 100 == last % 100) {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            cout << vis[i] << ' ';
            sum += vis[i];
        }
        cout << endl << sum << endl;
        exit(0);
    }
    if (ind == 6)
        return;
    for (auto i : num) {
        if (vis[i % 10])
            continue;
        if (last == -1 || last % 100 == i / 1000) {
            vis[i % 10] = i / 10;
            if (last == -1)
                start = i % 10;
            dfs(ind + 1, i / 10);
            vis[i % 10] = 0;
        }
    }
}
int main() {
    // so ugly code, it sucks me
    for (int i = 0; i < 6; i++)
        gen(i + 1, i);
    dfs(0);
    return 0;
}
