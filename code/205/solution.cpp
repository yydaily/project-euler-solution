#include <iostream>
using namespace std;
long long a[50];
long long b[50];
long long c[50];

void handler(bool is_a) {
    for (int i = 0; i < 50; i++)
        c[i] = 0;
    for (int i = is_a ? 4 : 6; i >= 1; i--)
        for (int j = 0; j <= 40; j++)
            c[j + i] += is_a ? a[j] : b[j];
    for (int i = 0; i < 50; i++)
        is_a ? a[i] = c[i] : b[i] = c[i];
}

int main() {
    for (int i = 0; i < 50; i++)
        a[i] = b[i] = 0;
    a[0] = b[0] = 1;
    for (int i = 1; i <= 9; i++)
        handler(true);
    for (int i = 1; i <= 6; i++)
        handler(false);
    long long sum = 0;
    long long win = 0;
    for (int i = 1; i < 50; i++) {
        for (int j = 1; j < 50; j++) {
            sum += a[i] * b[j];
            win += a[i] * b[j] * (i > j);
        }
    }
    cout << win << ' ' << sum << endl;
    printf("%.10f\n", win * 1.0 / sum);
    return 0;
}
