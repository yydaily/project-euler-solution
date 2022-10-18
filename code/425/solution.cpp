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
bool conn[e7];
bool handle(long long a) {
    bool debug = false;
    if (a == 11)
        debug = true;

    if (a < 10)
        return true;
    int max_v = 1;
    while (max_v * 10 <= a)
        max_v *= 10;
    if (a / (max_v / 10) % 10 != 0 && conn[a - a / max_v * max_v]) {
        if (debug)
            cout << 1 << endl;
        return true;
    }

    long long copy_a = a - max_v;
    while (copy_a >= max_v) {
        if (conn[copy_a]) {
            if (debug)
                cout << 2 << endl;
            return true;
        }
        copy_a -= max_v;
    }

    for (long long i = 1; i < max_v; i *= 10) {
        for (int j = a / i % 10; j >= 0; j--) {
            if (conn[a - i * j]) {
                return true;
            }
        }
    }
    return false;
}
void dfs(long long a, long long upper) {
    if (conn[a] || a > upper)
        return;
    conn[a] = true;
    for (int i = 1; i <= a; i *= 10) {
        for (int j = 0; j < 10; j++) {
            int now = i * j + a - (a / i % 10) * i;
            if (Prime::is_prime(now))
                dfs(now, upper);
        }
    }
}
long long F(long long upper) {
    conn[0]       = true;
    long long ans = 0;
    for (auto i : Prime::prime) {
        if (i >= upper)
            break;
        if (handle(i)) {
            dfs(i, i);
        } else
            ans += i;
    }
    return ans;
}
int main() {
    Prime::init(e7);
    cout << F(e7) << endl;
    return 0;
}
