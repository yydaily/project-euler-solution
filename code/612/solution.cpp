#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
__int128 cnt[2000];
long long upper = 18;
__int128 x      = 1000000000000000000LL;
long long mod   = 1000267129;
long long cal(int bitmask) { /*{{{*/
    int can_zero   = bitmask & 1;
    int cnt        = __builtin_popcount(bitmask) - can_zero;
    long long ret  = 0;
    long long base = 1;
    for (int i = 1; i <= upper; i++) {
        base *= cnt + (can_zero && i != 1);
        ret += base;
    }
    return ret;
} /*}}}*/
int main() {
    for (int i = 2; i < (1 << 10); i++) {
        cnt[i] = cal(i);
        for (int j = i & (i - 1); j > 0; j = i & (j - 1))
            cnt[i] -= cnt[j];
        cnt[i] %= mod;
    }
    __int128 ans = 0;
    for (int i = 2; i < (1 << 10); i++) {
        for (int j = 2; j < (1 << 10); j++) {
            if (i & j)
                continue;
            if (cnt[i] == 0 || cnt[j] == 0)
                continue;
            ans += cnt[i] * cnt[j];
        }
    }
    __int128 rans   = (x - 1) * (x - 2) / 2 - ans / 2;
    long long rrans = rans % mod;
    cout << rrans << endl;
    return 0;
}
