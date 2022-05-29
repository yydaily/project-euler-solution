#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
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

typedef long long ll;
const ll mod = 1e9;
ll add(ll a, ll b) { return (a + b) % mod; }
ll mul(ll a, ll b) { return a * b % mod; }
ll sum(ll a) { /*{{{*/
    // return sum_{i=1}^a i^2
    ll b = a + 1;
    ll c = 2 * a + 1;

    if (a % 2 == 0)
        a /= 2;
    else
        b /= 2;

    if (a % 3 == 0)
        a /= 3;
    else if (b % 3 == 0)
        b /= 3;
    else
        c /= 3;

    return (a % mod) * (b % mod) % mod * (c % mod) % mod;
} /*}}}*/
ll cal(ll l, ll r) { /*{{{*/
    // return sum_{i=l}^r i^2
    ll ret = sum(r);
    ret    = add(ret, mod - sum(l - 1));
    assert(ret >= 0);
    return ret;
} /*}}}*/
ll cal(ll upper) { /*{{{*/
    ll ret = 0;
    for (ll i = 1; i <= upper;) {
        ll l   = i;
        ll r   = upper / (upper / i);
        ll cnt = upper / i;
        ret    = add(ret, mul(cnt % mod, cal(l, r)));
        i      = r + 1;
    }
    return ret;
} /*}}}*/
int main() {
    // for(int i = 1;i<=6;i++) cout<<i<<' '<<cal(i)<<endl;
    cout << cal(1e8) << endl;
    cout << cal(1e15) << endl;
    return 0;
}
