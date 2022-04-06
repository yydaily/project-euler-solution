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
#define double long double

double cal(double a, double b, double c, int depth) {
    double k = a + b + c + 2 * sqrt(a * b + b * c + a * c);
    if (depth == 1)
        return 1 / k / k;
    return 1 / k / k + cal(a, b, k, depth - 1) + cal(a, c, k, depth - 1) + cal(b, c, k, depth - 1);
}
int main() {
    int depth   = 10;
    double init = 1.0 / (2 * sqrt(3) - 3);
    double ans  = 3 + 3 * cal(-1 / init, 1, 1, depth) + cal(1, 1, 1, depth);
    cout << 1 - ans / init / init << endl;
    return 0;
}
