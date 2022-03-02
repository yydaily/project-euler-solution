#include <bits/stdc++.h>

using namespace std;
const int value_upper = 300000;
int ans[52][value_upper]; // 用i个数字组成j的方案数
int back[52][value_upper];

void add(int a) {
    for (int i = 0; i <= 50; i++)
        for (int j = 0; j < value_upper - a; j++)
            if (ans[i][j] > 0) {
                back[i + 1][j + a] += ans[i][j];
                if (back[i + 1][j + a] > 2)
                    back[i + 1][j + a] = 2;
            }
    for (int i = 0; i <= 51; i++)
        for (int j = 0; j < value_upper; j++)
            ans[i][j] = back[i][j];
}

int main() {
    ans[0][0]  = 1;
    back[0][0] = 1;
    for (int i = 1; i <= 100; i++)
        add(i * i);
    int ret = 0;
    for (int i = 0; i < value_upper; i++)
        ret += (ans[50][i] == 1) * i;
    cout << ret << endl;
    return 0;
}
