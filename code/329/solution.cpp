#include "../template/prime.cpp"
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
__int128 gcd(__int128 a, __int128 b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
struct fac {
    __int128 upper;
    __int128 lower;

    fac() {}
    fac(__int128 a, __int128 b) {
        __int128 g = gcd(a, b);
        upper      = a / g;
        lower      = b / g;
    }
    void show() { cout << (long long)upper << ' ' << (long long)lower << endl; }
};

fac mul(fac a, fac b) { return fac(a.upper * b.upper, a.lower * b.lower); }

fac add(fac a, fac b) { return fac(a.upper * b.lower + b.upper * a.lower, a.lower * b.lower); }

fac now[501];
void handle(bool prime) {
    fac nxt[501];
    for (int i = 1; i <= 500; i++)
        nxt[i] = fac(0, 1);
    nxt[2]   = mul(now[1], fac(prime ? 2 : 1, 3));
    nxt[499] = mul(now[500], fac(prime ? 2 : 1, 3));

    for (int i = 2; i < 500; i++) {
        fac buf(Prime::is_prime(i - 1) == prime ? 2 : 1, 6);
        nxt[i - 1] = add(nxt[i - 1], mul(now[i], buf));
        buf        = fac(Prime::is_prime(i + 1) == prime ? 2 : 1, 6);
        nxt[i + 1] = add(nxt[i + 1], mul(now[i], buf));
    }
    for (int i = 1; i <= 500; i++)
        now[i] = nxt[i];
}
int main() {
    Prime::init(600);
    for (int i = 1; i <= 500; i++) {
        now[i] = fac(Prime::is_prime(i) ? 2 : 1, 1500);
    }

    string query = "PPPPNNPPPNPPNPN";
    for (int i = 1; i < query.length(); i++) {
        handle(query[i] == 'P');
    }

    fac ans(0, 1);
    for (int i = 1; i <= 500; i++) {
        ans = add(ans, now[i]);
    }
    cout << (long long)ans.upper << ' ' << (long long)ans.lower << endl;
    return 0;
}
