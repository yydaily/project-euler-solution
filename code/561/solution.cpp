#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long Q(long long a) {
    long long ret  = 0;
    long long base = 904962;
    a /= 2;
    while (a > 0) {
        a /= 2;
        ret += a * base;
    }
    return ret;
}
int main() {
    cout << Q(8) << endl;
    cout << Q(1e12) << endl;
    return 0;
}
