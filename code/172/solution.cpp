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

int num[20];
long long ans = 0;
long long fac(long long a) {
    if (a <= 1)
        return 1;
    return a * fac(a - 1);
}
long long C(int a, int b) { return fac(a) / fac(b) / fac(a - b); }
void cal() {
    long long buf = C(17, num[0]);
    int cnt       = 18 - num[0];
    for (int i = 1; i < 10; i++) {
        buf *= C(cnt, num[i]);
        cnt -= num[i];
    }
    ans += buf;
}
void dfs(int a, int need = 18) {
    if (need == 0) {
        cal();
        return;
    }
    if (a == 10)
        return;
    for (int i = 0; i <= min(3, need); i++) {
        num[a] = i;
        dfs(a + 1, need - i);
        num[a] = 0;
    }
}
int main() {
    dfs(0);
    cout << ans << endl;
    return 0;
}
