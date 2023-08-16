#include "../template/prime.cpp"
#include <iostream>/*{{{*/
const long long e3  = 1000;
const long long e6  = e3 * e3;
const long long mod = 1e16;
using namespace std; /*}}}*/
long long cnt[2][2 * e6];
void add(long long a[2 * e6], long long b[2 * e6], int now) {
    memset(b, 0, sizeof(long long) * 2 * e6);
    for (int i = 0; i < 2e6; i++) {
        if (a[i] == 0)
            continue;
        b[i]       = (b[i] + a[i]) % mod;
        b[i + now] = (b[i + now] + a[i]) % mod;
    }
}
int main() {
    Prime::init(2e6);
    long long sum = 0;
    cnt[0][0]     = 1;
    int index     = 0;
    for (auto i : Prime::prime) {
        if (i > 5000)
            break;
        add(cnt[index], cnt[index ^ 1], i);
        index ^= 1;
    }
    long long ans = 0;
    for (int i = 2; i < 2 * e6; i++) {
        if (!Prime::is_prime(i))
            continue;
        ans = (ans + cnt[index][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}
