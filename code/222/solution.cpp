#include <iostream>
#include <math.h>
int num[21];
long double cal(int a, int b) {
    long long x = (a + b) * (a + b);
    long long y = (100 - a - b) * (100 - a - b);
    return sqrt(x - y);
}
long double cal() {
    long double ans = num[0] + num[20];
    for (int i = 1; i < 21; i++)
        ans += cal(num[i - 1], num[i]);
    return ans * 1000;
}
int main() {
    // 30 ~ 50
    int i = 0;
    for (int j = 50; j >= 30; j -= 2)
        num[i++] = j;
    for (int j = 31; j <= 50; j += 2)
        num[i++] = j;
    printf("%.0Lf\n", cal());
    return 0;
}
