#include <iostream>/*{{{*/
const long long e9 = 1e9;
using namespace std; /*}}}*/
long long a[10];
void add(long long &a, long long b) { a = (a + b) % e9; }
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret * a) % e9;
        a = a * a % e9;
        b >>= 1;
    }
    return ret;
}
long long G(long long n) {
    a[0] = 0;
    while (n) {
        a[++a[0]] = n & 1;
        n >>= 1;
    }
    long long ans = 0;
    while (true) {
        if (a[1] != 0) {
            add(ans, a[1]);
            a[1] = 0;
            continue;
        }
        if (a[2] != 0) {
            a[2]--;
            add(ans, ans + 3);
            continue;
        }
        if (a[3] != 0) {
            a[3]--;
            long long added = (qpow(2, ans + 3) - 1) * (ans + 3) % e9;
            add(ans, added);
            continue;
        }
        if (a[4] != 0) {
            a[4]--;
            a[1] = a[2] = a[3] = ans + 2;
            ans += 1;
            continue;
        }
        break;
    }
    return ans;
}
int main() {
    long long ans = 0;
    for (int i = 1; i < 16; i++) {
        ans += G(i);
    }
    cout << ans % e9 << endl;
    return 0;
}
