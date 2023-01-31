#include "../template/prime.cpp"
#include <iostream>/*{{{*/
const long long e3  = 1000;
const long long e6  = e3 * e3;
const long long e9  = e6 * e3;
const long long e18 = e9 * e9;
using namespace std; /*}}}*/

long long cnt[e6];
long long real = 0;
long long cal(long long a, long long b) {
    long long ret = 0;
    while (a > 0) {
        ret += a / b;
        a /= b;
    }
    return ret;
}
long long cal(int prime) {
    long long c = cnt[prime];
    // ret! has c prime
    // ret/prime + ret/prime/prime + ... + ret/prime/.../prime >= c
    long long l = 0, r = prime * c;
    while (l + 5 <= r) {
        auto mid = (l + r) >> 1;
        if (cal(mid, prime) >= c)
            r = mid;
        else
            l = mid;
    }
    for (auto i = l; i <= r; i++) {
        if (cal(i, prime) >= c)
            return i;
    }
    return -1;
}
void add(int a) {
    while (a != 1) {
        int p = Prime::MinPrime(a);
        while (a % p == 0) {
            cnt[p] += 1234567890;
            a /= p;
        }
        real = max(real, cal(p));
    }
}
long long mul(long long a, long long b) {
    long long ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % e18;
        a = (a + a) % e18;
        b >>= 1;
    }
    return ret;
}

long long S(long long a) {
    long long ret = 0;
    for (int i = 2; i <= a; i++) {
        add(i);
        if (i >= 10)
            ret = (ret + real) % e18;
    }
    return ret;
}
int main() {
    Prime::init(e6);
    cout << S(e6) << endl;
    return 0;
}
