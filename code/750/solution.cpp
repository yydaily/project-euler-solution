#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
int num[1000];
int dis[1000][1000];
int ans[1000][1000];
int G(int n) {
    int now = 1;
    for (int i = 1; i <= n; i++) {
        now    = now * 3 % (n + 1);
        num[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[num[i]][num[j]] = abs(i - j);
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = j; i >= 1; i--) {
            if (i == j) {
                ans[i][j] = 0;
                continue;
            }
            ans[i][j] = 1e9;
            for (int k = i; k < j; k++) {
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k + 1][j] + dis[k][j]);
            }
        }
    }
    return ans[1][n];
}
int main() {
    cout << G(6) << endl;
    cout << G(16) << endl;
    cout << G(976) << endl;
    return 0;
}
