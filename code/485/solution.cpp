#include <iostream>/*{{{*/
#include <map>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
using namespace std; /*}}}*/
int p[e8];
int min_prime[e8 + 10];
int d[e8 + 10];
void init_d(long long u) {
    for (int i = 2; i <= u; i++) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            p[++p[0]]    = i;
        }
        for (int j = 1; j <= p[0]; j++) {
            if (1LL * i * p[j] >= e8)
                break;
            min_prime[i * p[j]] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }

    d[1] = 1;
    for (long long i = 2; i <= u; i++) {
        int cnt     = 1;
        long long p = min_prime[i];
        while (i % p == 0) {
            p *= min_prime[i];
            cnt++;
        }
        d[i] = d[i * min_prime[i] / p] * cnt;
    }
}
map<int, int> m;
int cal() {
    auto x = m.end();
    x--;
    while (x->second == 0) {
        m.erase(x);
        x--;
    }
    return x->first;
}
long long S(long long u, long long k) {
    // return \sum_{n=1}^{u-k+1} M(n, k)
    // M(n, k) = \max_{j=n}^{n+k-1} d(j)
    // return \max_{j=1}^k d(j) + \max_{j=2}^{k+1} d(j) + ... + \max_{u-k+1}^{u} d(j)
    init_d(u);

    for (int i = 1; i <= k; i++) {
        m[d[i]]++;
    }

    long long ans = 0;
    ans += cal();
    for (int j = 1; j <= u - k; j++) {
        m[d[j]]--;
        m[d[j + k]]++;
        ans += cal();
    }
    return ans;
}
int main() {
    init_d(e8 + 1);
    cout << S(1000, 10) << endl;
    cout << S(e8, e5) << endl;
    return 0;
}
