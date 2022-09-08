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
long long num[100];
long long ans = 0;
long long a, b, c, d; // a 个 b 面的筛子，最大的c个，和为d的方案数
long long C[100][100];
void init() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
long long check() {
    long long total    = 0;
    long long need_cnt = c;
    long long last     = a;
    long long buf_ans  = 1;
    for (long long i = b; i >= 1; i--) {
        total += i * min(need_cnt, num[i]);
        need_cnt -= min(need_cnt, num[i]);
        buf_ans *= C[last][num[i]];
        last -= num[i];
    }
    if (total != d)
        return 0;
    return buf_ans;
}

void dfs(long long a, long long b) { /*{{{*/
    // 还有a个筛子，最大选择为b
    if (b == 1 || a == 0) {
        num[b] = a;
        ans += check();
        return;
    }
    for (long long i = 0; i <= a; i++) {
        num[b] = i;
        dfs(a - i, b - 1);
    }
} /*}}}*/

int main() {
    // a = 5, b = 6, c = 3, d = 15;
    init();
    a = 20, b = 12, c = 10, d = 70;
    dfs(a, b);
    cout << ans << endl;
    return 0;
}
