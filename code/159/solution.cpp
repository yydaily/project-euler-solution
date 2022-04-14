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

int ans[e6];
int cal(int a) {
    int ret = (a - 1) % 9 + 1;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ret = max(ret, ans[i] + ans[a / i]);
        }
    }
    ans[a] = ret;
    return ret;
}
int main() {
    int ans = 0;
    for (int i = 2; i < e6; i++) {
        ans += cal(i);
    }
    cout << cal(24) << endl;
    cout << ans << endl;
    return 0;
}
