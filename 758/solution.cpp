#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int qpow(int a, long long b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
int cal(long long a, long long b) {
    // return (2^a-1) / (2^b-1)
    if (a < b)
        return 0;
    auto x1 = qpow(2, a % b);
    auto x2 = qpow(qpow(2, b), a / b);
    auto x3 = add(1, mod - x2);
    auto x4 = qpow(add(1, mod - qpow(2, b)), mod - 2);
    return mul(x1, mul(x3, x4));
}
bool exgcd(long long a, long long b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return true;
    }
    auto y_neg = exgcd(b, a % b, x, y);
    int t      = y;
    y          = add(x, mod - mul(y, cal(a, b)));
    x          = t;
    return !y_neg;
}
int get_ans(long long a, long long b) {
    int x, y;
    bool y_neg = exgcd(a, b, x, y);
    x          = mul(x, 2);
    y          = mul(y, 2);
    if (y_neg) {
        y = add(mod, -y);
    } else {
        x = add(mod, -x);
    }
    return add(add(mod, -2), add(x, y));
}
bool is_prime(int a) {
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main() {
    int ans = 0;
    vector<long long> prime;
    for (int i = 2; i < 1000; i++)
        if (is_prime(i))
            prime.push_back(1ll * i * i * i * i * i);
    for (int i = 0; i < prime.size(); i++) {
        for (int j = i + 1; j < prime.size(); j++) {
            ans = add(ans, get_ans(prime[i], prime[j]));
        }
    }
    cout << ans << endl;
    return 0;
}
