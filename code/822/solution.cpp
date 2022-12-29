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
#include <pthread.h>
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
long long _mod     = 1234567891;
using namespace std; /*}}}*/
long long qpow(long long a, long long b, long long mod = _mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

long long cnt[e5];

long long S(long long a, long long b) {
    cout << "S(" << a << ", " << b << ") = ";
    long long total_cnt = 0;
    for (int i = 2; i <= a; i++) {
        cnt[i] = b / (a - 1) - 4;
        if (cnt[i] <= 0)
            cnt[i] = 0;
        total_cnt += cnt[i];
    }

    while (total_cnt < b) {
        int index = 2;
        for (int i = 3; i <= a; i++) {
            if (log(index) / log(i) * pow(2, cnt[index] - cnt[i]) > 1)
                index = i;
        }
        total_cnt++;
        cnt[index]++;
    }

    long long ans = 0;
    for (int i = 2; i <= a; i++) {
        ans = (ans + qpow(i, qpow(2, cnt[i], _mod - 1))) % _mod;
    }
    return ans;
}
int main() {
    cout << S(5, 3) << endl;
    cout << S(10, 100) << endl;
    cout << S(e4, e8 * e8) << endl;
    return 0;
}
