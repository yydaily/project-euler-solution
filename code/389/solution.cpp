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

long double p4[5] = {0, 0.25, 0.25, 0.25, 0.25};
long double p6[25];
long double p8[193];
long double p12[2305];
long double p20[46081];

long double cache[2400][50000];
long double cal(int a, int b, int c) { /*{{{*/
    if (c < 0)
        return 0;
    if (cache[a][c] == -1)
        return 0;
    if (cache[a][c] > 0)
        return cache[a][c];
    if (c > a * b)
        return 0;
    if (a == 0 && c == 0)
        return 1;
    if (a == 0)
        return 0;
    long double ret = 0;
    for (int i = 1; i <= b; i++) {
        ret += cal(a - 1, b, c - i) / b;
    }
    if (ret == 0) {
        cache[a][c] = -1;
        return 0;
    }
    cache[a][c] = ret;
    return ret;
} /*}}}*/

void cal(int upper, int dim, long double *origin, long double *to) {
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= upper; i++) {
        for (int j = i; j <= dim * i; j++) {
            to[j] += origin[i] * cal(i, dim, j);
        }
    }
}

int main() {
    cal(4, 6, p4, p6);
    cal(24, 8, p6, p8);
    cal(192, 12, p8, p12);
    cal(2304, 20, p12, p20);

    long double exp = 0;
    for (int i = 1; i <= 46080; i++) {
        exp += p20[i] * i;
    }

    long double ans = 0;
    for (int i = 1; i <= 46080; i++) {
        long double diff = exp - i;
        ans += diff * diff * p20[i];
    }
    printf("%.4Lf\n", ans);
    return 0;
}
