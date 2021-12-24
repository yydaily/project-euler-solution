#include<bits/stdc++.h>

using namespace std;
long long mod = 1307674368000;

long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) {/*{{{*/
    long long ret = 0;
    while (b) {
        if (b & 1) ret = add(ret, a);
        a = add(a, a);
        b >>= 1;
    }
    return (ret + mod) % mod;
}/*}}}*/
struct matrix {
    long long num[3][3];

    matrix() {
        memset(num, 0, sizeof(num));
    }

    matrix(long long a, long long b, long long c) {
        memset(num, 0, sizeof(num));
        num[0][0] = a;
        num[1][0] = b;
        num[2][0] = c;
    }
};

matrix mul(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                c.num[i][k] = add(c.num[i][k], mul(a.num[i][j], b.num[j][k]));
            }
        }
    }
    return c;
}

matrix qpow(matrix a, long long b) {
    matrix ret;
    for (int i = 0; i < 3; i++) ret.num[i][i] = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

// return F_n(x)
long long cal(long long n, long long x) {
    n -= 2;
    matrix base;
    base.num[0][0] = base.num[2][1] = 1;
    base.num[0][1] = base.num[1][1] = x;
    base.num[0][2] = base.num[1][2] = mul(x, x);
    return mul(qpow(base, n), matrix(add(x, mul(x, x)), mul(x, x), x)).num[0][0];
}

int main() {
    long long ans = 0;
    long long n = 1;
    for (int i = 0; i < 15; i++) n *= 10;
    for (int i = 0; i <= 100; i++) ans = add(ans, cal(n, i));
    cout << ans << endl;
    cout << (ans == 252541322550) << endl;
    return 0;
}

