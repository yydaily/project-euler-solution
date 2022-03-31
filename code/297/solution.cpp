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

vector<long long> num;
map<long long, long long> m;
long long cnt(long long a) {
    if (a <= 0)
        return 0;
    if (m[a])
        return m[a];
    for (int i = num.size() - 1; i >= 0; i--) {
        if (a >= num[i]) {
            m[a] = 1 + cnt(num[i] - 1) + cnt(a - num[i]) + a - num[i];
            return m[a];
        }
    }
    return 0;
}

const long long upper = e8 * e9;
int main() {
    long long a = 1, b = 1;
    while (b < upper) {
        num.push_back(b);
        a += b;
        swap(a, b);
    }
    cout << cnt(upper - 1) << endl;
    return 0;
}
