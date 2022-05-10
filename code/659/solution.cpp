#include <iostream>/*{{{*/
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

long long ans[e7 + 10];
long long num[e7 + 10];

int main() {
    for (long long i = 1; i <= e7; i++)
        num[i] = 4 * i * i + 1;
    for (long long i = 1; i <= e7; i++) {
        long long p = num[i];
        if (p == 4 * i * i + 1)
            ans[i] = p;
        if (p <= 1)
            continue;
        for (long long j = i; j <= e7; j += p) {
            while (num[j] % p == 0) {
                ans[j] = max(ans[j], p);
                num[j] /= p;
            }
        }
        for (long long j = p - i; j <= e7; j += p) {
            if (j <= 0)
                continue;
            while (num[j] % p == 0) {
                ans[j] = max(ans[j], p);
                num[j] /= p;
            }
        }
    }
    long long rans = 0;
    long long mod  = e9 * e9;
    for (int i = 1; i <= e7; i++)
        rans = (rans + ans[i]) % mod;
    cout << rans << endl;
    return 0;
}
