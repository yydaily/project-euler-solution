#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
const int need_len = 10;
const int need_sum = need_len * (need_len - 1) / 2;
int cnt[need_len];
int cnt_sum   = 0;
int sum       = 0;
long long ans = 0;
long long C[15][15];

void init() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

void add() {
    long long buf = 1;
    int len = need_len, len2 = need_len;
    for (int i = 0; i < need_len; i++) {
        buf *= C[len - (i == 0)][cnt[i]];
        len -= cnt[i];

        buf *= C[len2][2 - cnt[i]];
        len2 -= 2 - cnt[i];
    }
    ans += buf;
}

void dfs(int index) {
    if (cnt_sum > need_len)
        return;
    if (index == need_len) {
        if (abs(2 * need_sum - 2 * sum) % 11 != 0 || cnt_sum != need_len)
            return;
        add();
        return;
    }
    for (int i = 0; i < 3; i++) {
        cnt[index] = i;
        sum += i * index;
        cnt_sum += i;
        dfs(index + 1);
        cnt_sum -= i;
        sum -= i * index;
        cnt[index] = 0;
    }
}

int main() {
    init();
    dfs(0);
    cout << ans << endl;
    return 0;
}
