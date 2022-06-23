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
long long _mod     = e9 + 7;
using namespace std; /*}}}*/

const long long mod      = 1234567891011LL;
const long long need_cnt = 100000;
const long long lower    = 1e14; // 1e14;
int main() {
    Fibonacci::init(mod);
    int cnt       = 0;
    long long ans = 0;
    for (long long i = lower;; i++) {
        if (Prime::miller_rabin(i)) {
            cnt++;
            cout << cnt / 1000 << endl;
            ans += Fibonacci::fib(i);
            ans %= mod;
        }
        if (cnt == need_cnt)
            break;
    }
    cout << ans << endl;
    return 0;
}
