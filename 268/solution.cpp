#include<bits/stdc++.h>

using namespace std;
const long long u = 1e16;
long long a[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
map<int, int> cnt_;

long long C(long long a, long long b) {
    long long ret = 1;
    for (int i = b + 1; i <= a; i++) ret = ret * i / (i - b);
    return ret;
}

void init() {
    cnt_[4] = 1;
    for (int i = 5; i <= 14; i++) {
        cnt_[i] = 0;
        for (int j = 4; j < i; j++) {
            cnt_[i] += cnt_[j] * C(i, j);
        }
        cnt_[i] = 1 - cnt_[i];
    }
}

long long cal(int buf) {
    long long x = 1;
    int cnt = 0;
    for (int i = 0; i < 25; i++)
        if (buf & (1 << i)) {
            x *= a[i];
            cnt++;
            if (x > u) return 0;
        }
    if (cnt < 4) return 0;
    return cnt_[cnt] * (u / x);
}


int main() {
    init();
    int upper = 1 << 25;
    long long ans = 0;
    for (int i = 1; i < upper; i++) ans += cal(i);
    cout << ans << endl;
    return 0;
}

