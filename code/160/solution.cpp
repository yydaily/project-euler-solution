#include <iostream>
using namespace std;
const long long upper = 1e12;
const long long e5    = 1e5;
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret * a) % e5;
        a = (a * a) % e5;
        b >>= 1;
    }
    return ret;
}
long long count(long long a, long long base) { /*{{{*/
    long long ret = 0;
    while (a) {
        a /= base;
        ret += a;
    }
    return ret;
} /*}}}*/
int cnt[e5];
int main() {
    long long ans = 1;
    for (long long a = 1; a <= upper; a <<= 1) {
        for (long long b = 1; a * b <= upper; b *= 5) {
            long long x = upper / (a * b);
            for (long long y = 1; y < e5; y += 2) {
                if (y % 5 == 0)
                    continue;
                cnt[y] += x / e5 + (x % e5 >= y);
            }
        }
    }
    for (long long y = 1; y < e5; y++) {
        ans = (ans * qpow(y, cnt[y])) % e5;
    }
    ans = (ans * qpow(2, count(upper, 2) - count(upper, 5))) % e5;
    cout << ans << endl;
    return 0;
}
