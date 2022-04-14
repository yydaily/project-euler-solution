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
const long long upper = (1LL << 50) - 1;
const long long MAXN  = (1 << 25) - 1;

bool check[MAXN + 10];
int prime[MAXN + 10];
int mu[MAXN + 10];
void Moblus() { /*{{{*/
    mu[1]   = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i]        = -1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] > MAXN)
                break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
} /*}}}*/
int main() {
    Moblus();
    long long ans = 0;
    for (int i = 1; i <= MAXN; i++) {
        ans += mu[i] * (upper / i / i);
    }
    cout << ans << endl;
    return 0;
}
