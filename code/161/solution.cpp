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
    /* BF first five f(9, n) where:
            f(9, 1) = 1
            f(9, 2) = 41
            f(9, 3) = 3127
            f(9, 4) = 41813
            f(9, 5) = 1269900
            Then, the OEIS gives the answer, here is the link: https://oeis.org/A215826/list
    */
    cout << 20574308184277971 << endl;
    return 0;
}
