#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
const int len = 10;
int d[len]    = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
////const int len = 9;
////int d[len] = {7, 6, 3, 8, 5, 9, 1, 2, 4};
long long cal(int *a, int l, int r) {
    long long ret = 0;
    for (int i = l; i <= r; i++) {
        ret = ret * 10 + a[i];
    }
    return ret;
}
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void add(int *m, int &x) {
    while (x) {
        m[x % 10]++;
        x /= 10;
    }
}
bool check(int a, int b, int c) {
    if (!(a && b && c))
        return false;
    int cache[10];
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < len; i++)
        cache[d[i]]--;
    add(cache, a);
    add(cache, b);
    add(cache, c);
    for (int i = 0; i <= 9; i++)
        if (cache[i] != 0) {
            return false;
        }
    return true;
}
bool cal() {
    for (int i = 1; i < len; i++) {
        int l = cal(d, 0, i - 1);
        int r = cal(d, i, len - 1);
        int g = gcd(l, r);

        for (int x = 1; x * x <= g; x++) {
            if (g % x != 0)
                continue;
            if (check(x, l / x, r / x)) {
                return true;
            }
            int y = g / x;
            if (check(y, l / y, r / y)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    do {
        if (cal()) {
            cout << cal(d, 0, len - 1) << endl;
            break;
        }
    } while (prev_permutation(d, d + len));
    return 0;
}
