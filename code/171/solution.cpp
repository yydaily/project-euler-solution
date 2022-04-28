#include <iostream>/*{{{*/
#include <math.h>
long long mod = 1e9;
using namespace std; /*}}}*/

int num[10];
int C[30][30];
long long ans = 0;
void init() {
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

bool check() {
    int total = 0;
    for (int i = 1; i <= 9; i++)
        total += num[i] * i * i;
    if (total == 0)
        return false;
    int t = sqrt(total);
    return t * t == total;
}

void cal() {
    long long base = 0;
    int len        = 0;
    for (int i = 0; i < 10; i++) {
        len += num[i];
        for (int j = 0; j < num[i]; j++)
            base = (base * 10 + 1) % mod;
    }
    __int128 cnt = 1;
    int l        = len;
    for (int i = 0; i < 10; i++) {
        cnt = cnt * C[l][num[i]];
        l -= num[i];
    }
    for (int i = 1; i < 10; i++) {
        ans = (ans + cnt * i * num[i] * base / len) % mod;
    }
}

void dfs1(int need, int index) {
    if (index == 10) {
        if (need != 0)
            return;
        if (check())
            cal();
        return;
    }
    for (int i = 0; i <= need; i++) {
        num[index] = i;
        dfs1(need - i, index + 1);
        num[index] = 0;
    }
}

int main() {
    init();
    dfs1(20, 0);
    cout << ans << endl;
    return 0;
}
