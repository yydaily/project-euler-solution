#include <iostream>
using namespace std;
long long ans = 0;
int d[20];
void check_and_sum() {
    int x0 = d[0], x1 = d[1], x2 = d[2], x3 = d[3];
    int x4 = d[4], x5 = d[5], x6 = d[6], x8 = d[7];
    int x10 = d[8];

    int sum = x0 + x1 + x2 + x3;
    int x7  = sum - x4 - x5 - x6;
    if (x7 < 0 || x7 > 9)
        return;
    int x12 = sum - x0 - x4 - x8;
    if (x12 < 0 || x12 > 9)
        return;
    int x14 = sum - x2 - x6 - x10;
    if (x14 < 0 || x14 > 9)
        return;
    int x15 = sum - x0 - x5 - x10;
    if (x15 < 0 || x15 > 9)
        return;
    int x11 = sum - x3 - x7 - x15;
    if (x11 < 0 || x11 > 9)
        return;
    int x9 = sum - x3 - x6 - x12;
    if (x9 < 0 || x9 > 9)
        return;
    int x13 = sum - x1 - x5 - x9;
    if (x13 < 0 || x13 > 9)
        return;
    if (x12 + x13 + x14 + x15 != sum)
        return;
    if (x8 + x9 + x10 + x11 != sum)
        return;
    ans++;
}
void dfs(int index = 0) {
    if (index == 9) {
        check_and_sum();
        return;
    }

    for (int i = 0; i < 10; i++) {
        d[index] = i;
        dfs(index + 1);
    }
}
int main() {
    dfs();
    cout << ans << endl;
    return 0;
}
