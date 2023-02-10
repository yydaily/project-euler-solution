#include <iostream>/*{{{*/
long long _mod     = 1008691207;
const long long e8 = 1e8;
using namespace std; /*}}}*/

long long fac[e8 + 10];
void init() {
    fac[0] = 1;
    for (int i = 1; i <= e8; i++)
        fac[i] = (fac[i - 1] * i) % _mod;
}

long long cal(int a) {
    long long ans1 = 1;
    for (int i = 1; i < a; i++)
        ans1 = (ans1 + fac[i] * 2) % _mod;
    long long ans2 = 0;
    for (int i = a - 1; i >= 1; i--)
        ans2 = (ans2 + fac[a - 1 - i] * i % _mod) % _mod;
    return ((fac[a] - ans1 + ans2) % _mod + _mod) % _mod;
}

int main() {
    init();
    cout << cal(3) << endl;
    cout << cal(5) << endl;
    cout << cal(e8) << endl;
    return 0;
}
