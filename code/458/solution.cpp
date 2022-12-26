#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
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
long long _mod     = e9;
using namespace std; /*}}}*/
typedef long long ll;
struct matrix {
    ll num[7][7];
    matrix() { memset(num, 0, sizeof(num)); };
    matrix(int a) {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < 7; i++)
            num[i][i] = a;
    }
};
matrix mul(const matrix &a, const matrix &b) {
    matrix ret;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                ret.num[i][k] = (ret.num[i][k] + a.num[i][j] * b.num[j][k]) % _mod;
            }
        }
    }
    return ret;
}
matrix qpow(matrix a, ll b) {
    matrix ret(1);
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
ll solve(ll a) {
    matrix start;
    start.num[0][1] = 7;
    for (int i = 1; i < 7; i++) {
        for (int j = 1; j <= min(i + 1, 6); j++) {
            start.num[i][j] = (j == i + 1 ? 7 - i : 1);
        }
    }
    start  = qpow(start, a);
    ll ans = 0;
    for (int i = 1; i < 7; i++)
        ans = (ans + start.num[0][i]) % _mod;
    return ans;
}
int main() {
    cout << solve(e6 * e6) << endl;
    return 0;
}
