#include <iostream>  /*{{{*/
using namespace std; /*}}}*/

const long long siz = 3 * 10000 * 1000;
long long cache[siz];
long long a(int n) {
    if (n < siz && cache[n])
        return cache[n];
    long long ret;
    if (n & 1) {
        ret = a(n / 2) - 3 * a(n / 2 + 1);
    } else {
        ret = 2 * a(n / 2);
    }
    if (n < siz)
        cache[n] = ret;
    return ret;
}

long long S(long long n) {
    long long x   = n / 2;
    long long ret = 1;
    while (x % 2 == 0) {
        x /= 2;
        ret *= 2;
    }
    ret *= a(x);
    return 4 - ret;
}

int main() {
    cache[1] = 1;
    cout << S(10) << endl;
    cout << S(1e12) << endl;
    return 0;
}
