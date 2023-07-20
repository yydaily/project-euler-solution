#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
const int len = 2e5 + 10;
int fac2[len], fac5[len];
int cal(int a, int base) {
    int ret = 0;
    while (a % base == 0) {
        ret++;
        a /= base;
    }
    return ret;
}
void init() {
    for (int i = 2; i < len; i++) {
        fac2[i] = fac2[i - 1] + cal(i, 2);
        fac5[i] = fac5[i - 1] + cal(i, 5);
    }
}

int C(int a, int b, int *fac) { return fac[a] - fac[b] - fac[a - b]; }
long long solve(int upper, int need2, int need5) {
    long long ans = 0;
    for (int i = 0; i <= upper; i++) {
        int cnt2 = C(upper, i, fac2);
        int cnt5 = C(upper, i, fac5);
        for (int j = 0; i + j <= upper; j++) {
            int cnt22 = cnt2 + C(upper - i, j, fac2);
            int cnt55 = cnt5 + C(upper - i, j, fac5);
            if (cnt22 >= need2 && cnt55 >= need5) {
                ans++;
            }
        }
    }
    return ans;
}
int main() {
    init();
    cout << solve(200000, 12, 12) << endl;
    return 0;
}
