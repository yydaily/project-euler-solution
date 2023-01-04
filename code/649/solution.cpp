#include <iostream>/*{{{*/
#include <map>
const long long mod = 1e9;
const long long e7  = 1e7;
using namespace std; /*}}}*/
int sg[e7 + 20];
long long cnt[10];
void init_sg() {
    sg[0] = 0;
    for (int i = 1; i < e7 + 20; i++) {
        map<int, int> m;
        if (i >= 2)
            m[sg[i - 2]] = true;
        if (i >= 3)
            m[sg[i - 3]] = true;
        if (i >= 5)
            m[sg[i - 5]] = true;
        if (i >= 7)
            m[sg[i - 7]] = true;
        for (int j = 0;; j++) {
            if (m[j])
                continue;
            sg[i] = j;
            break;
        }
    }
}

long long C[300][300];
void init_C() {
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}

long long pow(long long a, int b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

long long cal(int x[5], int sum) {
    long long ret = 1;
    for (int i = 0; i < 5; i++) {
        ret = ret * C[sum][x[i]] % mod * pow(cnt[i], x[i]) % mod;
        sum -= x[i];
    }
    return ret;
}

long long M(int a, int b) {
    b *= 2;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < a; i++)
        cnt[sg[i]]++;

    long long ans = 0;
    int x[5];
    for (x[4] = 0; x[4] <= b; x[4] += 2) { // sg值为4的数量一定是偶数
        for (x[1] = 0; x[1] + x[4] <= b; x[1]++) {
            for (x[2] = x[1] & 1; x[1] + x[2] + x[4] <= b; x[2] += 2) {
                for (x[3] = x[1] & 1; x[1] + x[2] + x[3] + x[4] <= b; x[3] += 2) {
                    x[0]   = b - x[1] - x[2] - x[3] - x[4];
                    auto v = cal(x, b);
                    ans += v;
                    if (ans > mod)
                        ans -= mod;
                }
            }
        }
    }
    return ((pow(a, b) - ans) % mod + mod) % mod;
}
int main() {
    init_sg();
    init_C();
    cout << M(3, 1) << endl;
    cout << M(3, 2) << endl;
    cout << M(9, 3) << endl;
    cout << M(e7 + 19, 100) << endl;
    return 0;
}
