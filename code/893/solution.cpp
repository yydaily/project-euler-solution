#include <iostream>
using namespace std;
const long long e6 = 100 * 100 * 100;
int add_and_multi[e6 + 5], multi[e6 + 5];
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int cal_origin(int a) {
    if (a < 10)
        return cost[a];
    return cal_origin(a / 10) + cost[a % 10];
}
long long solve(int a) {
    long long ret = 0;
    for (int i = 1; i <= a; i++) {
        int now = cal_origin(i);
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                now = min(now, multi[i / j] + multi[j] + 2);
            }
        }
        multi[i] = now;

        for (int j = 1; j + j <= i; j++) {
            now = min(now, add_and_multi[j] + add_and_multi[i - j] + 2);
        }
        add_and_multi[i] = now;
        ret += now;
    }
    return ret;
}
int main() {
    cout << solve(100) << endl;
    cout << solve(100 * 100) << endl;
    cout << solve(e6) << endl;
    return 0;
}
