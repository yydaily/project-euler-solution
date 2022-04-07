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

vector<__int128> v;
int main() {
    for (__int128 p = 1; p < 80000; p++) {
        __int128 now = p * p + 1;
        for (long long d = p; d >= 1; d--) {
            if (now % d == 0) {
                auto x = p * (p + d) * (p + now / d);
                if (x > 2e15)
                    break;
                v.push_back(x);
            }
        }
    }
    cout << v.size() << endl;
    sort(v.begin(), v.end());
    cout << (long long)v[150000 - 1] << endl;
    return 0;
}
