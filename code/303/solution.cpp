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

long long cal(int a) {
    struct p {
        long long now;
        long long mod;
        p(long long n, long long m) {
            now = n;
            mod = m;
        }
    };
    vector<p> x;
    vector<p> ano;
    x.push_back(p(0, 0));
    for (long long i = 1;; i *= 10) {
        for (auto j : x) {
            if (j.now || j.mod) {
                auto now = p(j.now * 10 + (j.mod * 10) / a, (j.mod * 10) % a);
                if (now.mod == 0)
                    return now.now;
                ano.push_back(now);
            }

            auto now = p(j.now * 10 + (j.mod * 10 + 1) / a, (j.mod * 10 + 1) % a);
            if (now.mod == 0)
                return now.now;
            ano.push_back(now);

            now = p(j.now * 10 + (j.mod * 10 + 2) / a, (j.mod * 10 + 2) % a);
            if (now.mod == 0)
                return now.now;
            ano.push_back(now);
        }
        swap(x, ano);
        ano.clear();
    }
}
int main() {
    long long ans = 0;
    for (int i = 1; i <= 10000; i++) {
        if (i == 9999)
            continue;
        ans += cal(i);
    }
    cout << ans + 1111333355557778LL << endl;
    return 0;
}
