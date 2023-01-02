#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = 1004535809;
using namespace std; /*}}}*/
int cnt[e5];
long long fac[e5];
void init() {
    Prime::init(e6);
    int last  = 0;
    int index = 0;
    for (auto i : Prime::prime) {
        cnt[index++] = i - last - 1;
        last         = i - 1;
    }
    fac[0] = 1;
    for (int i = 1; i < e5; i++)
        fac[i] = fac[i - 1] * i % _mod;
}
long long power(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % _mod;
        a = a * a % _mod;
        b >>= 1;
    }
    return ret;
}
long long C(int a, int b) { return fac[a] * power(fac[b], _mod - 2) % _mod * power(fac[a - b], _mod - 2) % _mod; }
int cache[2 * e4 + 10][2 * e4 + 10];
long long T(long long a, long long b) {
    // 长度为a, 素数一共b个，一个数最多选择maxm个素数的方案数
    if (b == 0) {
        // cout<<"T("<<a<<','<<b<<','<<maxm<<") = 1"<<endl;
        return 1;
    }
    if (a == 1) {
        return cnt[b];
    }
    if (cache[a][b])
        return cache[a][b];
    long long ans = 0;
    long long l = a >> 1, r = a - l;
    for (int i = 0; i <= b; i++) {
        ans = (ans + T(l, i) * T(r, b - i) % _mod) % _mod;
    }
    cache[a][b] = ans;
    return ans;
}
int main() {
    init();
    cout << T(3, 3) << endl;
    cout << T(10, 10) << endl;
    cout << T(e3, e3) << endl;
    cout << T(2 * e4, 2 * e4) << endl;
    return 0;
}
