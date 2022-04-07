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

const int people  = 100;
const int max_dis = people >> 1;
long double a[people + 10], b[people + 10];
void gao() {
    for (int i = 1; i <= max_dis; i++) {
        for (int x = 1; x <= 6; x++) {
            for (int y = 1; y <= 6; y++) {
                int dis = i + (x == 6) - (x == 1) + (y == 1) - (y == 6);
                if (dis == -1)
                    dis = 1;
                if (dis > max_dis)
                    dis = people - dis;
                b[dis] += 1.0 / 36 * a[i];
            }
        }
    }
}
int main() {
    a[max_dis]      = 1;
    long double ans = 0;
    for (long long i = 1; i < 100000; i++) {
        memset(b, 0, sizeof(b));
        gao();
        ans += i * b[0];
        for (int j = 1; j <= max_dis; j++)
            a[j] = b[j];
    }
    printf("%4.6Lf\n", ans);
    return 0;
}
