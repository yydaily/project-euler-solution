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
const long long upper = e6 * e6;
bool vis[e6 + 10];
int main() {
    // (a, b, c) -> a^{b^c} -> (a^{b^(c-1)})^b -> (a^{b^{c-1}}, b) -> (a, b, c-1, b) = (a, b, b, c-1)
    long long ans = 0;
    Prime::init(e6 + 10);
    for (long long i = 2; i <= e6; i++) {
        if (vis[i])
            continue;
        __int128 now  = i * i;
        long long pow = 2;
        while (now <= upper) {
            if (now <= e6)
                vis[now] = true;
            if ((!Prime::is_prime(i) || !Prime::is_prime(pow)) && now > 16) {
                ans += now;
            }
            now *= i;
            pow++;
        }
    }
    cout << ans << endl;
    return 0;
}
