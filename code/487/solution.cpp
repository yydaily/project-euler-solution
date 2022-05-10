#include "../template/prime.cpp"
#include "../template/sum_power.cpp"
#include <iostream>/*{{{*/
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = 998244353;
using namespace std; /*}}}*/

long long S(int k, long long n, long long mod) {
    long long ans = (n + 1) % mod * sum_power::solve(n, k) % mod;
    cout << k << ' ' << n << ' ' << ans;
    ans = (ans + mod - sum_power::solve(n, k + 1)) % mod;
    cout << ' ' << ans << endl;
    return ans;
}
int main() {
    sum_power::init(1e4 + 10, _mod);
    cout << 35375333830 % _mod << endl;
    cout << S(4, 100, _mod) << endl;

    long long ans = 0;
    for (long long i = 2e9 + 1; i <= 2e9 + 2000; i += 2) {
        if (Prime::miller_rabin(i)) {
            sum_power::init(1e4 + 10, i);
            long long v = S(10000, e6 * e6, i);
            // cout<<i<<' '<<v<<endl;
            ans += v;
        }
    }
    cout << ans << endl;
    return 0;
}
