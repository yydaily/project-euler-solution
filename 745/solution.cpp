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
long long upper = 100;
map<long long, long long> m;
vector<long long> base;
bool cmp(long long a, long long b) { /*{{{*/
    return abs(a) < abs(b);
} /*}}}*/
void dfs(__int128 b = 1, int ind = 0) { /*{{{*/
    for (int i = ind; i < Prime::prime.size(); i++) {
        __int128 buf = b * Prime::prime[i] * Prime::prime[i];
        if (b < 0)
            buf = -buf;
        if (buf > 1e14)
            break;
        if (b > 0)
            buf = -buf;
        base.push_back(buf);
        dfs(buf, i + 1);
    }
} /*}}}*/
long long cal(long long a, int ind = 0) {
    if (a <= 3)
        return a;
    long long ans = a;
    for (auto i : base) {
        long long v = a / i;
        if (v)
            ans += a / i;
        else
            break;
    }
    // cout<<ans<<endl;
    for (int i = ind; i < Prime::prime.size(); i++) {
        long long p = Prime::prime[i];
        if (a / p / p == 0)
            break;
        ans = add(ans, mul(p * p, cal(a / p / p, i)));
    }
    // cout<<"cal("<<a<<") = "<<ans<<endl;
    m[a] = ans;
    return ans;
}
int cal2(int a) {
    int maxm = 0;
    for (int i = 1; i * i <= a; i++) {
        if (a % i == 0 && (a / i) % i == 0)
            maxm = i * i;
    }
    return maxm;
}
int main() {
    Prime::init(e7);
    dfs();
    sort(base.begin(), base.end(), cmp);
    long long now = 1;
    for (int i = 1; i <= 14; i++) {
        now *= 10;
        cout << i << ' ' << cal(now) << endl;
    }
    return 0;
}
