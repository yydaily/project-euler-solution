#include <iostream>
using namespace std;
typedef long long ll;
ll f(ll a, ll b) {
    if (a <= b)
        return a;
    ll le = b, ri = b;
    for (ll i = 1;; i *= 2) {
        le = ri + 1;
        ri = ri + i;
        if (ri >= a) {
            return b + f(a, le);
        }
    }
}

inline ll xpow(ll a, ll b) {
    ll ret = 1;
    for (int i = 0; i < b; i++)
        ret *= a;
    return ret;
}

int main() {
    cout << f(6, 1) << endl;
    cout << f(10, 3) << endl;
    cout << f(xpow(10, 17), xpow(9, 17)) << endl;
    return 0;
}
