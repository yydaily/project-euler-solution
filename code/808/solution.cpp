#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
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
int num[100];
long long rev(long long a) {
    num[0] = 0;
    while (a) {
        num[++num[0]] = a % 10;
        a /= 10;
    }
    long long ret = 0;
    for (int i = 1; i <= num[0]; i++) {
        ret = ret * 10 + num[i];
    }
    return ret;
}
bool check(long long a) {
    long long l = a * a;
    long long r = rev(l);
    if (l == r)
        return false;

    long long sqrt_r = sqrt(r);
    if (sqrt_r * sqrt_r != r)
        return false;
    return Prime::is_prime(sqrt_r);
}
int main() {
    Prime::init(e8);
    long long ans = 0;
    int cnt       = 0;
    for (auto i : Prime::prime) {
        if (check(i)) {
            ans += 1ll * i * i;
            ++cnt;
            cout << cnt << ' ' << i << ' ' << 1LL * i * i << endl;
            if (cnt == 50)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
