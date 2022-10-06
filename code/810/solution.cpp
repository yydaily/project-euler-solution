#include <iostream>  /*{{{*/
using namespace std; /*}}}*/

const int upper = 3e8;
long long x(long long a, long long b) {
    long long ret = 0;
    while (b) {
        if (b & 1)
            ret ^= a;
        a <<= 1;
        b >>= 1;
    }
    if (ret > upper)
        ret = 1;
    return ret;
}

bool is_p[upper];

int solve(int n) {
    for (int i = 2; i < upper; i++) {
        if (!is_p[i]) {
            n--;
            if (n == 0)
                return i;
            for (int j = i; i * j < upper; j++) {
                is_p[x(i, j)] = true;
            }
        }
    }
    return -1;
}

int main() {
    cout << x(3, 7) << endl;
    cout << solve(5000000) << endl;
    return 0;
}
