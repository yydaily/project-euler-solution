#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long pow(long long a, long long b, long long mod) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

const long long mod  = 815730721;
const long long mod2 = 752982204;
const long long mod3 = 231686832;
const long long mod4 = 71288256;
const long long mod5 = 21934848;
const long long mod6 = 6749184;
long long C(long long n, long long mod, long long mod2) {
    long long ans1 = pow(2, pow(3, n - 2, mod2), mod);
    // cout<<pow(3, n-3, mod2)<<endl;
    long long ans2 = pow(3, (pow(3, n - 3, mod2) - 1) / 2 * 3, mod);
    return ans1 * ans2 % mod;
}

long long C3(long long n) {
    long long a = C(n, mod5, mod6);
    long long b = C(a, mod3, mod4);
    return C(b, mod, mod2);
}

int main() {
    cout << C(10000, mod, mod2) << endl;
    cout << C3(10000) << endl;
    return 0;
}
