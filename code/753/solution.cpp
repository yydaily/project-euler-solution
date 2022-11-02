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
long long cal(long long p) {
    if (p % 3 == 2)
        return (p - 1) * (p - 2);
    int a, b;
    for (a = sqrt(p) * 2; a >= 0; a--) {
        b = sqrt((4 * p - a * a) / 27);
        if (4 * p == a * a + 27 * b * b) {
            if (a % 3 == 1)
                return (p + a - 8) * (p - 1);
            else
                return (p - a - 8) * (p - 1);
        }
    }
}
int main() {
    Prime::init(6 * e6);
    long long ans = 2;
    for (int i = 2; i < Prime::prime.size(); i++) {
        ans += cal(Prime::prime[i]);
    }
    cout << ans << endl;
    return 0;
}
