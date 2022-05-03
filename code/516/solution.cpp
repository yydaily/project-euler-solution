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
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
using namespace std; /*}}}*/

// const long long upper = e6*e6;
const __int128 upper = e6 * e6;
vector<__int128> v;
void init() { /*{{{*/
    for (__int128 i = 1; i <= upper; i *= 2) {
        for (__int128 j = i; j <= upper; j *= 3) {
            for (__int128 k = j; k <= upper; k *= 5) {
                if (Prime::is_prime(k + 1))
                    v.push_back(k + 1);
            }
        }
    }
} /*}}}*/

__int128 mod = 1LL << 32;
map<__int128, bool> vis;
__int128 cal(__int128 base, int index) {
    __int128 ret = 0;
    for (int i = index; i < v.size(); i++) {
        if (v[i] * base > upper)
            return ret;
        if (vis[v[i] * base])
            continue;
        vis[v[i] * base] = true;
        ret              = (ret + (v[i] % mod) * (base % mod)) % mod;
        ret              = (ret + cal(v[i] * base, i + 1));
    }
    return ret;
}
int main() {
    Prime::init(e6);
    init();
    sort(v.begin(), v.end());
    __int128 ans = 0;
    for (__int128 i = 1; i <= upper; i *= 2) {
        for (__int128 j = i; j <= upper; j *= 3) {
            for (__int128 k = j; k <= upper; k *= 5) {
                cout << (long long)k << endl;
                ans = (ans + cal(k, 0) % mod) % mod;
            }
        }
    }
    ans %= mod;
    long long rans = ans + 1;
    cout << rans << endl;
    return 0;
}
