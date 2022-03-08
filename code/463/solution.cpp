#include <iostream>
using namespace std;
const int maxm = 1e7 + 10;
const int mod  = 1e9;
inline int add(long long a, long long b) { return (a + b) % mod; }
inline int mul(long long a, long long b) { return a * b % mod; }
int num[maxm];
int sum[maxm];
long long f(long long a) {
    if (a < maxm && num[a])
        return num[a];
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    if (a == 3)
        return 3;
    if ((a & 1) ^ 1)
        return f(a >> 1);
    else if ((a & 3) == 3)
        return add(mul(3, f(a >> 1)), mod - (f(a >> 2) << 1));
    else
        return add((f(a >> 1 | 1) << 1), mod - f(a >> 2));
}
long long S(long long a) {
    if (a < maxm)
        return sum[a];
    long long ret = 0;
    if (a % 4 == 3) {
        ret = add(ret, mul(6, S(a >> 1)));
        ret = add(ret, mod - mul(8, S(a >> 2)));
        ret = add(ret, mod - 1);
    } else {
        while (a % 4 != 3)
            ret = add(ret, mod - f(++a));
        ret = add(ret, S(a));
    }
    return ret;
}
int main() {
    for (int i = 1; i < maxm; i++)
        num[i] = f(i), sum[i] = add(sum[i - 1], num[i]);
    long long nouse = 1;
    for (int i = 1; i <= 37; i++) {
        nouse = (nouse << 2) - nouse;
    }
    cout << S(nouse) << endl;
    return 0;
}
