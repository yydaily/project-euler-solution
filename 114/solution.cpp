#include <iostream>
using namespace std;
long long num[1000];  // black end
long long num1[1000]; // red end
long long cal(long long n, long long m) {
    // n blocks, m at least
    memset(num, 0, sizeof(num));
    memset(num1, 0, sizeof(num1));
    num[0] = 1;

    for (long long i = 1; i <= n; i++) {
        num[i] = num[i - 1] + num1[i - 1];
        if (i >= m) {
            for (long long j = i - m; j >= 0; j--) {
                num1[i] += num[j];
            }
        }
    }
    return num[n] + num1[n];
}
int main() {
    cout << cal(50, 3) << endl;
    return 0;
}
