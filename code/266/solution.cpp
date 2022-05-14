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

struct p {
    long double v;
    int index;
    p() {}
    p(long double x) { v = x; }
    bool operator<(const p &a) const { return v < a.v; }
} l[1 << 21], r[1 << 21];
long double upper = 1.0;
long double cal(int index, bool show_detail = false) {
    auto i = upper_bound(r, r + (1 << 21), p(upper / l[index].v));
    i--;
    if (show_detail) {
        __int128 ans = 1.0;
        for (int ind = 0; ind < 21; ind++) {
            if (i->index & (1 << ind))
                cout << Prime::prime[ind + 21] << ' ', ans = (ans * Prime::prime[ind + 21]) % (e8 * e8);
            if (index & (1 << ind))
                cout << Prime::prime[ind] << ' ', ans = (ans * Prime::prime[ind]) % (e8 * e8);
        }
        cout << endl;
        long long rans = ans;
        cout << rans << endl;
    }
    return i->v * l[index].v;
}
int main() {
    Prime::init(190); // 42 primes
    for (auto i : Prime::prime)
        upper *= i;
    upper = sqrt(upper);

    for (int i = 0; i < (1 << 21); i++) {
        l[i].v = r[i].v = 1.0;
        l[i].index = r[i].index = i;
        for (int j = 0; j < 21; j++)
            if (i & (1 << j))
                l[i].v *= Prime::prime[j], r[i].v *= Prime::prime[j + 21];
    }
    sort(r, r + (1 << 21));

    int index = 0;
    for (int i = 1; i < (1 << 21); i++) {
        if (upper / cal(i) < upper / cal(index))
            index = i;
    }
    cal(index, true);
    return 0;
}
