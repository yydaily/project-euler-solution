#include <iostream>
#include <map>
#include <math.h>
using namespace std;
const int N = 1e9;
map<int, long long> m;
long long cal(long long n) {
    if (m[n])
        return m[n];
    int z         = sqrt(n);
    long long ret = n * n / 8;
    for (int g = 3; g <= z; g += 2) {
        ret -= cal(n / g);
    }
    for (int x = 1; x <= n / (z + 1); x++) {
        ret -= ((n / x + 1) / 2 - (n / (x + 1) + 1) / 2) * cal(x);
    }
    m[n] = ret;
    return ret;
}
int main() {
    cout << 1 + 2 * cal(N) << endl;
    return 0;
}
