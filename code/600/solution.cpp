#include <bits/stdc++.h>
using namespace std;
long long cal2(int x) {
    auto lower = x % 2 + 1;
    auto upper = x + 1;
    auto len   = (upper - lower) / 2 + 1;
    return 1ll * (lower + upper) * len / 2;
}
long long cal(int x) {
    long long ret = 0;
    for (int a = 1; a * 3 <= x; a++)
        ret += cal2(x - a * 3);
    return ret;
}
int upper = 55106;
int main() {
    long long ans = 0;
    for (int d = 0; d * 3 + 6 <= upper; d++)
        ans += cal((upper - d * 3) / 2);
    cout << ans << endl;
    return 0;
}
