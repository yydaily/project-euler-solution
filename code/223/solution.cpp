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
const long long upper = 25000000;
void merge(map<long long, long long> &v, long long x) { /*{{{*/
    while (x != 1) {
        v[Prime::min_prime[x]]++;
        x /= Prime::min_prime[x];
    }
} /*}}}*/
void merge(vector<long long> &factor, long long prime, long long cnt) { /*{{{*/
    if (factor.size() == 0)
        factor.push_back(1);
    long long base = 1;
    long long len  = factor.size();
    for (long long i = 1; i <= cnt; i++) {
        base *= prime;
        for (long long j = 0; j < len; j++) {
            factor.push_back(factor[j] * base);
        }
    }
} /*}}}*/
long long cal(long long a) { /*{{{*/
    map<long long, long long> pc;
    merge(pc, a + 1);
    merge(pc, a - 1);

    vector<long long> factor;
    for (auto i : pc) {
        merge(factor, i.first, i.second);
    }

    long long ret = 0;
    long long u   = (a - 1) * (a + 1);
    for (auto i : factor) {
        long long j = u / i;
        assert(i * j == u);
        if (j > i)
            continue;
        // c+b = i
        // c-b = j
        if ((i ^ j) & 1)
            continue;
        long long c = (i + j) / 2;
        long long b = i - c;
        if (c < b || b < a || a + b + c > upper)
            continue;
        // cout<<a<<' '<<b<<' '<<c<<endl;
        ret++;
    }
    return ret;
} /*}}}*/
int main() {
    // a*a + b*b = c*c + 1
    // (c+b)*(c-b) = (a+1)*(a-1)
    Prime::init(upper);
    long long ans = (upper - 1) / 2;
    for (long long i = 2; i <= upper / 3; i++) {
        cout << i << endl;
        ans += cal(i);
    }
    cout << ans << endl;
    return 0;
}
