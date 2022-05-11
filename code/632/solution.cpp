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

long long upper = 1e16;
long long dfs(long long need, __int128 now, long long index) {
    if (need == 0)
        return upper / now;
    long long ret = 0;
    for (int i = index; i < Prime::prime.size(); i++) {
        if (now * Prime::prime[i] * Prime::prime[i] > upper)
            break;
        ret += dfs(need - 1, now * Prime::prime[i] * Prime::prime[i], i + 1);
    }
    return ret;
}
long long num[10];
long long fac(long long a) {
    if (a <= 1)
        return 1;
    return fac(a - 1) * a;
}
int main() {
    Prime::init(e8);
    num[0] = upper;
    for (int i = 8; i >= 1; i--) {
        num[i] = dfs(i, 1, 0);
        for (int j = i + 1; j <= 8; j++) {
            num[i] -= fac(j) / fac(i) / fac(j - i) * num[j];
        }
        num[0] -= num[i];
    }
    __int128 ans = 1;
    for (int i = 0; i <= 8; i++) {
        ans = ans * num[i] % _mod;
    }
    long long rans = ans;
    cout << rans << endl;
    return 0;
}
