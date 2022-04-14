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

vector<int> v;
void gen(int ind = 0, long long now = 1) {
    while (now * Prime::prime[ind] <= e9) {
        now *= Prime::prime[ind];
        v.push_back(now);
        gen(ind + 1, now);
    }
}
set<int> s;
int main() {
    Prime::init(e5);
    gen();
    sort(v.begin(), v.end());
    long long ans = 0;
    for (auto i : v) {
        for (int add = 2;; add++) {
            if (Prime::is_prime(i + add)) {
                s.insert(add);
                break;
            }
        }
    }
    for (auto i : s)
        ans += i;
    cout << ans << endl;
    return 0;
}
