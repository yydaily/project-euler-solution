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

const int upper = 64 * e6;

bool check(int a) {
    long long now = 1;
    while (a != 1) {
        int p         = Prime::MinPrime(a);
        int cnt       = 0;
        long long buf = 1;
        while (a % p == 0) {
            a /= p;
            cnt++;
            buf = buf * p * p + 1;
        }
        now *= buf;
    }
    long long s = sqrt(now);
    return s * s == now;
}

int main() {
    Prime::init(32 * e3);
    long long ans = 0;
    for (int i = 1; i < upper; i++) {
        if (check(i)) {
            cout << i << endl;
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
