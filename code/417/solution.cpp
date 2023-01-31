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
int cache[e8 + 10];
long long qpow(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) {
    if (a == 0)
        return b;
    return a / gcd(a, b) * b;
}
void cal_prime_power(int prime, int prime_power, int upper) {
    int t = prime_power / prime * (prime - 1);
    while (prime_power % 2 == 0)
        prime_power /= 2;
    while (prime_power % 5 == 0)
        prime_power /= 5;
    if (prime_power == 1)
        return;
    int ret = t;
    int buf = t;
    while (buf != 1) {
        int p = Prime::MinPrime(buf);
        if (qpow(10, ret / p, prime_power) == 1) {
            ret /= p;
        }
        buf /= p;
    }
    for (int j = 1; j * prime_power <= upper; j++) {
        cache[prime_power * j] = lcm(cache[prime_power * j], ret);
    }
}

long long solve(long long upper) {
    for (int i = 3; i <= upper; i++) {
        if (i == 2 || i == 5 || !Prime::is_prime(i))
            continue;
        long long now = i;
        while (now <= upper) {
            cal_prime_power(i, now, upper);
            now *= i;
        }
    }
    long long ret = 0;
    for (int i = 3; i <= upper; i++) {
        int buf = i;
        while (buf % 2 == 0)
            buf /= 2;
        while (buf % 5 == 0)
            buf /= 5;
        if (buf == 1)
            continue;
        if (cache[buf] == 0) {
            cout << buf << ' ' << cache[buf] << endl;
            exit(0);
        }
        // cout<<i<<' '<<cache[buf]<<endl;
        ret += cache[buf];
    }
    return ret;
}
int main() {
    Prime::init(e8 + 10);
    cout << solve(e6) << endl;
    cout << solve(e8) << endl;
    return 0;
}
