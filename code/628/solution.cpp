#include <iostream>/*{{{*/
long long mod      = 1008691207;
const long long e8 = 1e8;
using namespace std; /*}}}*/

long long cal(int a) {
    long long fac  = 1; // fac[0] = 1
    long long ans1 = 1;
    long long ans2 = 0;
    for (int i = 1; i < a; i++) {
        ans2 = (ans2 + fac * (a - i)) % mod;
        fac  = fac * i % mod;
        ans1 = (ans1 + fac * 2) % mod;
    }
    return ((fac * a - ans1 + ans2) % mod + mod) % mod;
}

int main() {
    cout << cal(3) << endl;
    cout << cal(5) << endl;
    cout << cal(e8) << endl;
    return 0;
}
