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
const int len = 4;
int a[len]    = {1, 1, 1, 1};
long double cal(int a[len]) {
    int sum_cnt = 0;
    for (int i = 0; i < len; i++)
        sum_cnt += a[i];
    long double ret = 0;
    if (sum_cnt == 1) {
        if (a[len - 1] == 1)
            return 0;
        ret++;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] == 0)
            continue;
        int x[len] = {0};
        for (int j = 0; j < len; j++)
            x[j] = a[j];
        x[i]--;
        for (int j = i + 1; j < len; j++)
            x[j]++;
        ret += a[i] / (double)sum_cnt * cal(x);
    }
    return ret;
}
int main() {
    printf("%.6Lf\n", cal(a));
    return 0;
}
