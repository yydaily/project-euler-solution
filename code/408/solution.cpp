#include <iostream>/*{{{*/
#include <iostream>
#include <vector>

namespace FacInv {
std::vector<long long> fac, fac_inv;
long long _mod = 1e9 + 7;

long long pow(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void init(int length = 1e6, int mod = 1e9 + 7) {
    _mod = mod;
    fac.resize(length + 1);
    fac_inv.resize(length + 1);

    fac[0] = 1;
    for (int i = 1; i <= length; i++)
        fac[i] = fac[i - 1] * i % _mod;

    fac_inv[length] = pow(fac[length], _mod - 2, _mod);
    for (int i = length - 1; i >= 0; i--) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % _mod;
    }
}

long long C(int n, int k) {
    if (n < k)
        return 0;
    if (n >= fac.size()) {
        std::cout << "n >= fac.size()" << std::endl;
        exit(0);
    }
    return fac[n] * fac_inv[k] % _mod * fac_inv[n - k] % _mod;
}
} // namespace FacInv
long long mod = 1e9 + 7;
using namespace std; /*}}}*/
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vector<pair<int, int>> gen(long long upper) {
    vector<pair<int, int>> res;
    for (long long n = 1; n * n * n * n < upper; n++) {
        for (long long m = n + 1; 4 * m * n * n * m <= upper; m++) {
            long long a = m * m - n * n;
            long long b = 2 * m * n;
            if (gcd(a, b) != 1)
                continue;
            long long u = min(upper / a / a, upper / b / b);
            for (long long base = 1; base * base <= u; base++) {
                res.push_back(make_pair(a * a * base * base, b * b * base * base));
                res.push_back(make_pair(b * b * base * base, a * a * base * base));
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
inline long long to(int a, int b) { return FacInv::C(a + b, b); }
long long P(int n) {
    auto poi = gen(n);
    vector<long long> ways(poi.size(), 0);
    FacInv::init(n * 2, mod);
    long long ans = to(n, n);
    for (int i = 0; i < poi.size(); i++) {
        ways[i] = to(poi[i].first, poi[i].second);
        for (int j = 0; j < i; j++) {
            if (poi[i].second < poi[j].second)
                continue;
            ways[i] = ((ways[i] - ways[j] * to(poi[i].first - poi[j].first, poi[i].second - poi[j].second) % mod) % mod + mod) % mod;
        }
        ans = ((ans - ways[i] * to(n - poi[i].first, n - poi[i].second) % mod) % mod + mod) % mod;
    }

    return ans;
}

int main() {
    cout << P(5) << endl;
    cout << P(16) << endl;
    cout << P(1000) << endl;
    cout << P(1e7) << endl;
    return 0;
}
