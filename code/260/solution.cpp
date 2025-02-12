#include <iostream>
using namespace std;
const int maxm = 1000;
char ans[maxm + 1][maxm + 1][maxm + 1];
void mark(int i, int j, int k) {
    for (int a = 1; a <= maxm; a++) {
        if (i + a <= maxm && ans[i + a][j][k] == -1) {
            ans[i + a][j][k] = 1;
        }
        if (j + a <= maxm && ans[i][j + a][k] == -1) {
            ans[i][j + a][k] = 1;
        }
        if (k + a <= maxm && ans[i][j][k + a] == -1) {
            ans[i][j][k + a] = 1;
        }

        if (i + a <= maxm && j + a <= maxm && ans[i + a][j + a][k] == -1) {
            ans[i + a][j + a][k] = 1;
        }
        if (i + a <= maxm && k + a <= maxm && ans[i + a][j][k + a] == -1) {
            ans[i + a][j][k + a] = 1;
        }
        if (j + a <= maxm && k + a <= maxm && ans[i][j + a][k + a] == -1) {
            ans[i][j + a][k + a] = 1;
        }
        if (i + a <= maxm && j + a <= maxm && k + a <= maxm && ans[i + a][j + a][k + a] == -1) {
            ans[i + a][j + a][k + a] = 1;
        }
    }
}
int main() {
    memset(ans, 0xff, sizeof(ans));
    for (int i = 0; i <= maxm; i++) {
        for (int j = 0; j <= maxm; j++) {
            for (int k = 0; k <= maxm; k++) {
                if (ans[i][j][k] == -1) {
                    ans[i][j][k] = 0;
                    mark(i, j, k);
                }
            }
        }
    }
    long long rans = 0;
    for (int i = 0; i <= maxm; i++) {
        for (int j = i; j <= maxm; j++) {
            for (int k = j; k <= maxm; k++) {
                if (ans[i][j][k] == 0) {
                    rans += i + j + k;
                }
            }
        }
    }
    cout << rans << endl;
    return 0;
}
