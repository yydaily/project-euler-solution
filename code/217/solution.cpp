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
long long mod      = 14348907;
using namespace std; /*}}}*/

long long add(long long a, long long b) { return (a + b) % mod; }
long long mul(long long a, long long b) { return 1LL * a * b % mod; }
long long num[100];

map<long long, map<long long, long long>> m, m2;
// exactly len, sum of digits
long long cnt(long long len, long long sum, bool start = true) { /*{{{*/
    if (start && sum == 0)
        return 0;
    if (start && m[len][sum])
        return m[len][sum];
    if (!start && m2[len][sum])
        return m2[len][sum];
    if (len < 0)
        return 0;
    if (len == 0 && sum == 0)
        return 1;
    if (sum > 9 * len)
        return 0;
    if (sum == 0)
        return start ? 0 : 1;
    long long v = 0;
    for (long long i = (start ? 1 : 0); i <= 9; i++) {
        if (i > sum)
            break;
        v = add(v, cnt(len - 1, sum - i, false));
    }
    if (start)
        m[len][sum] = v;
    else
        m2[len][sum] = v;
    return v;
} /*}}}*/
// at most len, sum of digits
long long cnt2(long long len, long long sum, bool start = true) { /*{{{*/
    if (sum == 0)
        return 1;
    if (len == 0)
        return 0;
    long long ret = 0;
    for (long long i = 1; i <= len; i++) {
        ret = add(ret, cnt(i, sum));
    }
    return ret;
} /*}}}*/

void init() {
    num[0] = 1;
    for (long long i = 1; i < 100; i++)
        num[i] = mul(num[i - 1], 10);
}
long long pow10(long long a) { return num[a]; }
long long cal(long long len) {
    long long sub_len = len / 2;
    long long ret     = 0;
    // 计算前半部分的和
    for (long long i = 1; i <= sub_len * 9; i++) { // 前一半的和
        for (long long j = 1; j <= sub_len; j++) { // 计算第 j 位的贡献
            auto f = cnt2;
            if (j != 1)
                f = cnt;
            for (long long k = 1; k <= min(i, 9LL); k++) { // 第 j 位是k
                long long base1 = f(sub_len - 1, i - k, true);
                long long base2 = ((len & 1) ? 10 : 1);
                long long base3 = cnt2(sub_len, i);
                long long base4 = mul(k, pow10(sub_len + (len & 1) + sub_len - j));
                ret             = add(ret, mul(mul(base1, base2), mul(base3, base4)));
            }
        }
    }
    // 计算中间部分的和
    if (len & 1) {
        for (long long i = 1; i <= sub_len * 9; i++) {
            for (long long j = 1; j < 10; j++) {
                long long base1 = cnt(sub_len, i);
                long long base2 = cnt2(sub_len, i);
                ret             = add(ret, mul(mul(base1, base2), mul(j, pow10(sub_len))));
            }
        }
    }

    // 计算后半部分的和
    for (long long i = 1; i <= sub_len * 9; i++) {
        for (long long j = 1; j <= sub_len; j++) {
            for (long long k = 1; k <= min(i, 9LL); k++) {
                long long base1 = cnt(sub_len, i);
                long long base2 = cnt2(sub_len - 1, i - k);
                long long base3 = ((len & 1) ? 10 : 1);
                long long base4 = mul(k, pow10(j - 1));
                ret             = add(ret, mul(mul(base1, base2), mul(base3, base4)));
            }
        }
    }
    return ret;
}

int main() {
    init();
    long long ans = 45;
    for (long long i = 2; i <= 47; i++)
        ans = add(ans, cal(i));
    cout << ans << endl;
    return 0;
}
