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
long long cnt(long long a) {
    long long ret = (1 << a) - a - 1;
    for (long long i = 1; i <= a; i++) {
        ret = ret * (26 - i + 1) / i;
    }
    return ret;
}
int main() {
    long long ans = 0;
    for (int i = 1; i <= 26; i++) {
        ans = max(ans, cnt(i));
        cout << cnt(i) << endl;
    }
    cout << ans << endl;
    return 0;
}
