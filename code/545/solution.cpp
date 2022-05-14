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

bool vis[e7];
map<long long, int> get_all_primes(long long a) { /*{{{*/
    map<long long, int> ret;
    for (auto prime : Prime::prime) {
        if (prime * prime > a)
            break;
        while (a % prime == 0) {
            ret[prime]++;
            a /= prime;
        }
    }
    if (a > 1)
        ret[a]++;
    return ret;
} /*}}}*/
vector<long long> get_all_divisors(long long a) { /*{{{*/
    auto m = get_all_primes(a);
    vector<long long> ret;
    ret.push_back(1);
    for (auto x : m) {
        long long b = 1;
        vector<long long> buf;
        for (int nouse = 0; nouse <= x.second; nouse++) {
            for (auto i : ret)
                buf.push_back(i * b);
            b *= x.first;
        }
        swap(ret, buf);
    }
    return ret;
} /*}}}*/
long long get_denominator(long long n) { /*{{{*/
    auto all_divisors = get_all_divisors(n);
    long long ret     = 1;
    for (auto divisor : all_divisors) {
        if (Prime::is_prime(divisor + 1)) {
            ret *= divisor + 1;
        }
    }
    return ret;
} /*}}}*/
long long cal(int n) { /*{{{*/
    if (n == 1)
        return 308;
    int count = 1;
    memset(vis, false, sizeof(vis));
    for (int i = 2; i < e7; i++) {
        if (vis[i])
            continue;
        auto denominator = get_denominator(308 * i);
        if (denominator != 20010) {
            for (int j = i; j < e7; j += i)
                vis[j] = true;
        } else {
            count++;
            if (count % 1000 == 0)
                cout << count << ' ' << i << endl;
            if (count == n)
                return 308 * i;
        }
    }
    assert(false);
} /*}}}*/

int main() {
    Prime::init(e7);
    cout << cal(100000) << endl;
    return 0;
}
