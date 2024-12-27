#include <iostream>
using namespace std;
const long long mod = 1e9 + 7;
long long add(long long a, long long b) {
    a %= mod;
    b %= mod;
    return (a + b + mod) % mod;
}
long long mul(long long a, long long b) {
    a %= mod;
    b %= mod;
    return a * b % mod;
}
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
const long long upper = 1e18;
long long check(long long a, long long ind) { /*{{{*/ return ind % (a * 2) >= a ? 1 : 0; } /*}}}*/
long long cal0(long long a, long long u) {                                                 // 0..u 里面有多少个数 & a == 0{{{
    u++;
    auto ans1 = u / (a * 2) * a;
    auto ans2 = min(a, u % (a * 2));
    return ans1 + ans2;
} /*}}}*/
long long cal(__int128 a) {
    __int128 r          = cal0(a, upper);
    __int128 l          = cal0(a, upper - a + 1);
    __int128 first_num0 = 0;
    if (cal0(a, upper) == cal0(a, upper - 1)) {
        first_num0 = r * a;
        r -= l;
        first_num0 -= r * (r + 1) / 2;
    } else {
        first_num0 = l * a;
        r -= l;
        first_num0 += r * (r + 1) / 2;
    }
    assert(first_num0 > 0);
    long long num0 = mul(mul(first_num0 / a / a + 1, add(first_num0 % mod, first_num0 % (a * a) % mod)), qpow(2, mod - 2));
    long long num1 = mul(upper + 1, mul(upper + 2, qpow(2, mod - 2)));
    // cout<<a<<' '<<num0<<' '<<num1<<endl;
    return mul(add(num1, -num0), mul(a, 2));
}
int main() {
    long long ans = 0;
    for (long long i = 1; i <= upper; i *= 2) {
        ans = add(ans, cal(i));
    }
    cout << ans << endl;
    return 0;
}
