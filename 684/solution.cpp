#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) { /*{{{*/
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
} /*}}}*/
long long add(long long cnt, ...) { /*{{{*/
    va_list buf;
    va_start(buf, cnt);
    long long ret = 0;
    while (cnt--)
        ret = add(ret, va_arg(buf, long long));
    return ret;
} /*}}}*/
long long mul(long long a, long long b) { /*{{{*/
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (1LL * a * b) % mod;
} /*}}}*/
long long mul(long long cnt, ...) { /*{{{*/
    va_list buf;
    va_start(buf, cnt);
    long long ret = 1;
    while (cnt--) {
        long long v = va_arg(buf, long long);
        ret         = mul(ret, v);
    }
    return ret;
} /*}}}*/
long long qpow(long long a, long long b) { /*{{{*/
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
} /*}}}*/
long long cal(long long n) { /*{{{*/
    // return a, a-1, a-2, ..., 54321
    long long inv_81 = qpow(81, mod - 2);
    long long base   = mul(3, 9, n, qpow(10, n));
    base             = add(3, base, -qpow(10, n), 1);
    return mul(base, inv_81);
} /*}}}*/
long long S(long long a) { /*{{{*/
    long long cnt   = a / 9;
    long long m     = a - cnt * 9;
    long long inv_9 = qpow(9, mod - 2);
    long long inv_2 = qpow(2, mod - 2);
    // 10^0 ~ 10^{cnt-1}
    long long x = mul(add(qpow(10, cnt), -1), inv_9);

    long long ans = mul(45, x);
    ans           = add(ans, mul(3, a, 9, x));
    ans           = add(ans, -mul(81, cal(cnt)));
    ans           = add(ans, mul(4, m, m + 1, inv_2, qpow(10, cnt)));
    return ans;
} /*}}}*/
int main() {
    long long a = 1, b = 1;
    long long ans = 0;
    for (int i = 2; i <= 90; i++) {
        ans = add(ans, S(b));
        swap(a, b);
        b += a;
    }
    cout << ans << endl;
    return 0;
}
