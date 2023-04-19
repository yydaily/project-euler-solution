#include <iostream>/*{{{*/
long long mod = 987654321;
using namespace std; /*}}}*/
long long S(long long l, long long r) {
    long long ret = 0;
    if (r <= 4) {
        for (long long i = l; i <= r; i++) {
            if (i == 1)
                ret++;
            else
                ret += 2;
        }
        return ret;
    }
    if (l == r) {
        return (4 * S(l / 4, l / 4) % mod - 2 * (l % 4 <= 1 ? 1 : 0) + mod) % mod;
    }
    if (r - l < 8) {
        for (long long i = l; i <= r; i++) {
            ret = (ret + S(i, i)) % mod;
        }
        return ret;
    }

    long long ll = l / 4 * 4;
    if (ll < l)
        ll += 4;
    ret = (ret + S(l, ll - 1)) % mod;

    long long rr = r / 4 * 4 - 1;
    ret          = (ret + S(rr + 1, r)) % mod;

    ret = (ret + 16 * S(ll / 4, rr / 4) % mod - 4 * (rr / 4 - ll / 4 + 1) % mod) % mod;

    return (ret + mod) % mod;
}
int main() {
    cout << S(1, 1) << endl;
    cout << S(9, 9) << endl;
    cout << S(1000, 1000) << endl;
    cout << S(1, 1000) << endl;
    cout << S(1, 1e18) << endl;
    return 0;
}
