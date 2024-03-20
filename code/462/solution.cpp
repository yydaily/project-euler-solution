#include <iomanip>
#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/

bool vis[100][100];

void F(long long upper) {
    memset(vis, false, sizeof(vis));
    long double ans = 0;
    int cnt         = 0;
    for (long long i = 0, base2 = 1; base2 <= upper; base2 *= 2, i++) {
        for (long long j = 0, base3 = base2; base3 <= upper; base3 *= 3, j++) {
            vis[i][j] = true;
            cnt++;
            ans += log(cnt); // cnt!
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (!vis[i][j])
                break;

            int cnt = -1;
            for (int k = i; vis[k][j]; k++) {
                cnt++;
            }
            for (int k = j; vis[i][k]; k++) {
                cnt++;
            }
            ans -= log(cnt);
        }
    }

    cout << setprecision(11) << exp(ans) << endl;
}

int main() {
    F(6);
    F(8);
    F(20);
    F(1000);
    F(1e18);
    return 0;
}
