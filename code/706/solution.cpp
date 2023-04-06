#include <iostream>/*{{{*/
long long _mod = 1e9 + 7;
using namespace std;       /*}}}*/
long long pre[3][3][3][3]; // 前缀 %3=0, %3=1, %3=2; 一共%3=0数量
long long nxt[3][3][3][3];
void add(long long &a, long long &b, long long c) { a = (a + b * c) % _mod; }
void gen() {
    memset(nxt, 0, sizeof(nxt));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    // 0, 3, 6, 9
                    add(nxt[(i + 1) % 3][j][k][(l + i + 1) % 3], pre[i][j][k][l], 4);
                    // 1, 4, 7
                    add(nxt[k][(i + 1) % 3][j][(l + k) % 3], pre[i][j][k][l], 3);
                    // 2, 5, 8
                    add(nxt[j][k][(i + 1) % 3][(l + j) % 3], pre[i][j][k][l], 3);
                }
            }
        }
    }

    memcpy(pre, nxt, sizeof(nxt));
}
long long cal(int cnt) {
    memset(pre, 0, sizeof(pre));
    pre[1][0][0][1] = 3; // 3, 6, 9
    pre[0][1][0][0] = 3; // 1, 4, 7
    pre[0][0][1][0] = 3; // 2, 5, 8
    for (int i = 1; i < cnt; i++) {
        gen();
    }
    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                ans += pre[i][j][k][0];
            }
        }
    }
    return ans;
}
int main() {
    cout << cal(2) << endl;
    cout << cal(6) << endl;
    cout << cal(1e5) << endl;
    return 0;
}
