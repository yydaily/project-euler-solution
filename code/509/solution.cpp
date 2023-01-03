#include <iostream>/*{{{*/
long long _mod = 1234567890;
using namespace std; /*}}}*/
long long cnt[50];
long long S(long long a) {
    cnt[0] = a / 2 + a % 2;
    cnt[1] = a - cnt[0];
    for (int i = 2; cnt[i - 1] > 0; i++) {
        cnt[i] = cnt[i - 1] / 2;
        cnt[i - 1] -= cnt[i];
    }
    for (int i = 0; cnt[i] > 0; i++) {
        cnt[i] %= _mod;
    }

    long long ret = 0;
    for (int i = 0; cnt[i] > 0; i++) {
        for (int j = 0; cnt[j] > 0; j++) {
            for (int k = 0; cnt[k] > 0; k++) {
                if ((i ^ j ^ k) != 0) {
                    ret = (ret + cnt[i] * cnt[j] % _mod * cnt[k] % _mod) % _mod;
                }
            }
        }
    }
    return ret;
}
int main() {
    cout << S(10) << endl;
    cout << S(100) << endl;
    cout << S(123456787654321) << endl;
    return 0;
}
