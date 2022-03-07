#include "../template/bigint.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const int e2  = 100;
const int e3  = e2 * 10;
const int e4  = e3 * 10;
const int e5  = e4 * 10;
const int e6  = e4 * e2;
const int e7  = e6 * 10;
const int e8  = e7 * 10;
const int mod = 1e9 + 7;
using namespace std; /*}}}*/

/*add{{{*/
template <typename T> T base_add(T a, T b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
template <typename T> T add(const T &t) { return t; }
template <typename T, typename... Args> T add(const T &t, const Args &...args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T> T base_mul(T a, T b) {
    a %= mod;
    b %= mod;
    T ret(0);
    while (b) {
        if (b & 1)
            ret = (ret + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return ret;
}
template <typename T> T mul(const T &t) { return t; }
template <typename T, typename... Args> T mul(const T &t, const Args &...args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T> T qpow(T a, T b) {
    T ret(1);
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
/*}}}*/

long long upper;
long long min_prime[e6 + 1];
void init() { /*{{{*/
    for (long long i = 2; i <= e6; i++) {
        if (min_prime[i] == 0)
            for (long long j = i; j <= e6; j += i)
                min_prime[j] = i;
    }
} /*}}}*/
map<vector<long long>, bool> m;
long long cal(vector<long long> &v) { /*{{{*/
    if (m[v])
        return 0;
    m[v] = true;

    long long base = 1;
    for (auto i : v)
        base *= i * i * i;
    base = upper / base;
    if (base == 0)
        return 0;

    long long ret = 0;

    vector<long long> num;
    num.push_back(1);
    while (true) {
        vector<long long> nxt;
        for (auto i : num) {
            ret += base / i;
            for (auto j : v) {
                if (i * j <= base)
                    nxt.push_back(i * j);
            }
        }
        sort(nxt.begin(), nxt.end());
        num.clear();
        if (nxt.size() == 0)
            break;
        num.push_back(nxt[0]);
        for (auto i : nxt) {
            if (i == num.back())
                continue;
            num.push_back(i);
        }
    }

    // cout<<"= "<<ret<<endl;
    return ret;
} /*}}}*/

long long cal(long long u) {
    m.clear();
    upper         = u;
    long long ans = upper;
    for (long long i = 2; i * i * i <= upper; i++) {
        vector<long long> v;
        auto base = i;
        while (base != 1) {
            v.push_back(min_prime[base]);
            base /= min_prime[base];
        }
        sort(v.begin(), v.end());
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        ans += cal(v);
    }
    return ans;
}
int main() {
    init();
    cout << 16 << ' ' << cal(16) << endl;
    cout << 100 << ' ' << cal(100) << endl;
    cout << 10000 << ' ' << cal(10000) << endl;
    cout << 1000000000000000000LL << ' ' << cal(1000000000000000000LL) << endl;
    return 0;
}
