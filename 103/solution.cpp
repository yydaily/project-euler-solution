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

const int len = 7;
int num[len]  = {0};
map<int, int> m;
bool check(int len) { /*{{{*/
    m.clear();
    vector<int> val;
    for (int i = 1; i < (1 << len); i++) {
        int sum = 0;
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            if (i & (1 << j)) {
                sum += num[j];
                cnt++;
            }
        }
        if (m[sum])
            return false;
        val.push_back(sum);
        m[sum] = cnt;
    }
    sort(val.begin(), val.end());
    for (int i = 1; i < val.size(); i++) {
        if (m[val[i]] < m[val[i - 1]])
            return false;
    }
    return true;
} /*}}}*/
void dfs(int l, int remain, int minm) {
    int maxm = remain / l;
    if (l == 1) {
        num[len - 1] = remain;
        if (check(len)) {
            for (int i = 0; i < len; i++)
                cout << num[i];
            cout << endl;
            exit(0);
        }
        return;
    }
    for (int i = minm; i <= maxm; i++) {
        num[len - l] = i;
        if (!check(len - l + 1)) {
            continue;
        }
        dfs(l - 1, remain - i, i);
    }
}
int main() {
    for (int i = 115;; i++) {
        cout << "dfs " << i << endl;
        dfs(len, i, 1);
    }
    return 0;
}
