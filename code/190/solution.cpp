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

double cal(int a) {
    // a*(a+1)/2
    double ret = 1.0;
    for (int i = 1; i <= a; i++) {
        double now = 2.0 * i / (a + 1);
        ret *= pow(now, i);
    }
    return ret;
}

int main() {
    long long ret = 0;
    for (int i = 2; i <= 15; i++) {
        long long now = cal(i);
        cout << i << ' ' << now << endl;
        ret += now;
    }
    cout << ret << endl;
    return 0;
}
