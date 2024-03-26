#include <iostream>/*{{{*/
#include <map>
const long long mod  = 998244353;
const long long inv2 = 499122177;
using namespace std; /*}}}*/
map<long long, long long> cache;
long long S(long long n) {
    if (cache[n])
        return cache[n];

    if (n == 1)
        return cache[1] = 1;
    long long ret = n % mod * ((n + 1) % mod) % mod * inv2 % mod;

    for (long long i = 2; i <= n; i++) {
        long long nxt = n / (n / i);

        long long now = S(n / i) * ((nxt - i + 1) % mod) % mod;
        ret           = ((ret - now) % mod + mod) % mod;
        i             = nxt;
    }

    return cache[n] = ret;
}
long long G(long long n) {
    long long ans = 0;
    for (long long u = 1; u <= n; u++) {
        long long nxt = n / (n / u);
        // u ~ nxt 之间都是一样的
        long long base1 = (u + nxt) % mod * ((nxt - u + 1) % mod) % mod * inv2 % mod;
        ans             = (ans + base1 * S(n / u)) % mod;

        u = nxt;
    }
    return ans;
}
int main() {
    cout << G(10) << endl;
    cout << G(100000000000LL) << endl;
    return 0;
}
