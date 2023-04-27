#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
long long mul(long long a, long long b, long long m) {
    if (m <= 1e8)
        return a * b % m;
    long long ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ret;
}
long long qpow(long long a, long long b, long long m) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ret;
}

/*
\begin{align*}
    ans &= \left\lfloor \cfrac{2^{2^p}}{p} \right\rfloor \% 2^p \% p\\
    &= \left( \cfrac{2^{2^p}}{p} - \cfrac{2^{2^p \% (p-1)}}{p} \right) \% 2^p \% p\\
    &= - \cfrac{2^{2^p \% (p-1)}\%p}{p} \% 2^p \% p\\
    &= - (2^{2^p \% (p-1)}\%p) * \left(\left\lfloor \cfrac{2^p}{p} \right\rfloor \cdot \left\lfloor \cfrac{p}{2} \right\rfloor + 1\right) \% 2^p \% p\\
    &= - (2^{2^p \% (p-1)}\%p) * \left(\left( \cfrac{2^p - 2}{p} \right) \cdot \left( \cfrac{p-1}{2} \right) + 1\right) \% 2^p \% p\\
    &= - (2^{2^p \% (p-1)}\%p) * \left(\left( \cfrac{(2^{p-1} - 1)\cdot(p-1)}{p} \right) + 1\right) \% 2^p \% p\\
    &= - (2^{2^p \% (p-1)}\%p) * \left(\left( \cfrac{p\cdot 2^{p-1} - p - 2^{p-1} + 1}{p} \right) + 1\right) \% 2^p \% p\\
    &= - (2^{2^p \% (p-1)}\%p) * \left( \cfrac{p\cdot 2^{p-1} - 2^{p-1} + 1}{p}\right) \% 2^p \% p\\
\end{align*}
令 $a = 2^{2^p \% (p-1)} \% p$，易得$a < p$
\begin{align*}
    ans &= -a *  \left( \cfrac{p\cdot 2^{p-1} - 2^{p-1} + 1}{p}\right) \% 2^p \% p\\
    &= (a * 2^{p-1} + a * \cfrac{2^{p-1}-1}{p}) \% 2^p \% p \\
    &= ((a\%2)*2^{p-1} + a*\cfrac{2^{p-1}-1}{p}) \% 2^p \% p \\
    &= ((a\%2)*2^{p-1} + a*\cfrac{2^{p-1}-1}{p}) \% p \\
    &= ((a\%2)*2^{p-1} + a*\cfrac{2^{p-1}\%p^2 - 1}{p}) \% p
\end{align*}
*/

long long g(long long p) {
    long long a = qpow(2, qpow(2, p, p - 1), p);

    long long ans1 = (a & 1) * qpow(2, p - 1, p);

    long long ans2 = qpow(2, p - 1, p * p);
    ans2 -= 1;
    if (ans2 < 0)
        ans2 += p * p;
    assert(ans2 % p == 0);
    ans2 /= p;
    ans2 = mul(ans2, a, p);

    return (ans1 + ans2) % p;
}

long long G(long long n) {
    long long ans = 0;

    vector<bool> prime(n + 1, true);
    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            p.push_back(i);
        for (auto pri : p) {
            if (1LL * i * pri > n)
                break;
            prime[i * pri] = false;
            if (i % pri == 0)
                break;
        }
    }

    for (int i = 1; i < p.size(); i++) {
        ans += g(p[i]);
    }

    return ans;
}

int main() {
    cout << G(100) << endl;
    cout << G(1e4) << endl;
    cout << G(1e7) << endl;
    return 0;
}
