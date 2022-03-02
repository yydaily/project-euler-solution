#include <iostream>
using namespace std;
const int mod = 1e9;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
struct Matrix {
    int num[11][11];
    Matrix() { memset(num, 0, sizeof(num)); }
    void init(int a[11][11]) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                num[i][j] = a[i][j];
            }
        }
    }
};
Matrix mul(Matrix a, Matrix b) {
    Matrix ret;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            for (int k = 0; k < 11; k++)
                ret.num[i][k] = add(ret.num[i][k], mul(a.num[i][j], b.num[j][k]));
    return ret;
}
Matrix qpow(Matrix a, long long b) {
    Matrix ret;
    for (int i = 0; i < 11; i++)
        ret.num[i][i] = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
int main() {
    int b[11][11] = {
        {1, 0, 0, 2, 1, 0, 0, 1, 1, 7, mod - 2}, {0, 0, 0, 1, 1, 0, 0, 0, 1, 1, mod - 1}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},       {0, 0, 0, 1, 0, 0, 0, 1, 0, 6, mod - 1}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},       {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    };
    Matrix base;
    base.init(b);
    long long power = 1e18;
    auto ret        = qpow(base, power - 4);

    int ans = 0;
    ans     = add(ans, mul(2, ret.num[0][0]));
    ans     = add(ans, mul(2, ret.num[0][5]));
    ans     = add(ans, ret.num[0][9]);
    ans     = add(ans, ret.num[0][10]);
    cout << ans << endl;
    return 0;
}
