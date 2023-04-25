#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
long long L(long long n) {
    long long m   = sqrt(n - 1);
    long long ret = m * m * (1 + m) * (1 + m) / 4 - m * m * n;
    for (int i = 1; i <= m; i++) {
        ret += (n - 1) / i * (2 * n - i * (1 + (n - 1) / i));
    }
    return ret;
}
int main() {
    // Sum_{k=1..n-1} Sum_{i=1..n-1} floor(k/i)
    cout << L(1000) << endl;
    cout << L(1e7) << endl;
    return 0;
}
