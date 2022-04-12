#include <iostream>
using namespace std;
typedef long long LL;
LL prime[6] = {2, 3, 5, 233, 331}; /*{{{*/
LL qmul(LL x, LL y, LL mod) { return (x * y - (long long)(x / (long double)mod * y + 1e-3) * mod + mod) % mod; }
LL qpow(LL a, LL n, LL mod) {
    LL ret = 1;
    while (n) {
        if (n & 1)
            ret = qmul(ret, a, mod);
        a = qmul(a, a, mod);
        n >>= 1;
    }
    return ret;
}
bool IsPrime(LL p) {
    if (p < 2)
        return 0;
    if (p != 2 && p % 2 == 0)
        return 0;
    LL s = p - 1;
    while (!(s & 1))
        s >>= 1;
    for (int i = 0; i < 5; ++i) {
        if (p == prime[i])
            return 1;
        LL t = s, m = qpow(prime[i], s, p);
        while (t != p - 1 && m != 1 && m != p - 1) {
            m = qmul(m, m, p);
            t <<= 1;
        }
        if (m != p - 1 && !(t & 1))
            return 0;
    }
    return 1;
} /*}}}*/
bool check(long long a) {
    if (a % 3 == 0)
        return false;
    if (a % 7 == 0)
        return false;
    if (a % 13 == 0)
        return false;
    a *= a;
    if (!IsPrime(a + 1))
        return false;
    if (!IsPrime(a + 3))
        return false;
    if (!IsPrime(a + 7))
        return false;
    if (!IsPrime(a + 9))
        return false;
    if (IsPrime(a + 11))
        return false;
    if (!IsPrime(a + 13))
        return false;
    if (IsPrime(a + 17))
        return false;
    if (IsPrime(a + 19))
        return false;
    if (IsPrime(a + 21))
        return false;
    if (IsPrime(a + 23))
        return false;
    if (!IsPrime(a + 27))
        return false;
    return true;
}
int main() {
    long long ans = 0;
    for (long long i = 1; i < 1.5e7; i++) {
        // if(i%1000==0) cout<<"handle "<<i*10<<endl;
        if (check(i * 10)) {
            ans += i * 10;
            cout << i * 10 << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
