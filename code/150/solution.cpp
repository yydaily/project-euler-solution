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

long long t = 0;
int mod1    = 1 << 20;
int mod2    = 1 << 19;
int gen() {
    t = (615949 * t + 797807) % mod1;
    return t - mod2;
}
long long sum[1010][1010];
int main() {
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            sum[i][j] = sum[i][j - 1] + gen();
        }
    }
    long long ans = 2e9;
    for (int i = 1000; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            long long now = 0;
            for (int l = 0; l <= 1000 - i; l++) {
                now += sum[i + l][j + l] - sum[i + l][j - 1];
                ans = min(ans, now);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
