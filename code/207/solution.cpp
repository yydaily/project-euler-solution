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

int main() {
    int a = 0, b = 0;
    for (long long k = 3;; k += 2) {
        // k*k = 1+4*m
        b++;
        if (__builtin_popcount(k + 1) == 1)
            a++;
        if (a * 12345 < b) {
            cout << (k * k - 1) / 4 << endl;
            break;
        }
    }
    return 0;
}
