#include <iostream>
using namespace std;
typedef long long ll;

ll L(ll a) {
    ll ans = 0;
    for (ll i = 1; i <= a; i *= 2) {
        ll cnt  = min(a, 2 * i - 1) - i + 1;
        ll cnt2 = (a + 1) / 2 / i;
        ans += cnt * cnt2 * 2;
    }
    for (ll i = 1; i <= a; i = i * 2 + 1) {
        ans--;
    }
    return ans;
}

ll qpow(ll a, ll b) {
    ll ret = 1;
    for (int i = 0; i < b; i++) {
        ret *= a;
    }
    return ret;
}

int main() {
    cout << L(7) << endl;
    cout << L(7 * 7) << endl;
    cout << L(qpow(7, 17)) << endl;
    return 0;
}