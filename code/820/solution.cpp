#include <iostream>
using namespace std;
inline long long qpow(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
long long S(long long a) {
    long long ret = 0;
    auto cal      = [](long long a, long long b) { return (qpow(10, b, a * 10) / a) % 10; };
    for (int i = 1; i <= a; i++) {
        ret += cal(i, a);
    }
    return ret;
}
int main() {
    cout << S(7) << endl;
    cout << S(100) << endl;
    cout << S(1000 * 1000 * 10) << endl;
    return 0;
}
