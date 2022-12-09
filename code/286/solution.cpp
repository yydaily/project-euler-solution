#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
double dp[51][51];
double cal(double a) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= 50; i++) {
        for (int j = 0; j < 50; j++) {
            dp[i][j] += dp[i - 1][j] * i / a;
            if (j) {
                dp[i][j] += dp[i - 1][j - 1] * (1 - i / a);
            }
        }
    }
    return dp[50][20];
}
int main() {
    double l = 50, r = 100;
    while (r - l >= 1e-12) {
        if (cal((l + r) / 2) > 0.02)
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    }
    printf("%.10f\n", l);
    return 0;
}
