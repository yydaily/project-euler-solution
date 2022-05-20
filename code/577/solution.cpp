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

long long cal(long long n) {
    long long base = 15 * n * n * n * n + 270 * n * n * n + 1665 * n * n;
    if (n % 3 == 0)
        base += 4050 * n + 3240;
    else if (n % 3 == 1)
        base += 4170 * n + 3600;
    else
        base += 3930 * n + 2520;
    return base / 3240;
}
int main() {
    long long ans = 0;
    for (long long i = 3; i <= 12345; i++) {
        ans += cal(i - 3);
    }
    cout << ans << endl;
    return 0;
}
