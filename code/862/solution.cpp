#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long fac[14];
void init() {
    fac[0] = 1;
    for (int i = 1; i < 14; i++)
        fac[i] = fac[i - 1] * i;
}
int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
long long total_length;
long long calculate() {
    long long now = total_length;
    long long ans = fac[now - 1] / fac[cnt[0]] / fac[now - cnt[0] - 1];
    for (int i = 1; i < 10; i++) {
        now -= cnt[i - 1];
        ans *= fac[now] / fac[cnt[i]] / fac[now - cnt[i]];
    }
    return ans * (ans - 1) / 2;
}
long long dfs(int remain, int start = 1) {
    if (remain == 0) {
        return calculate();
    }
    if (start == 9) {
        cnt[9]        = remain;
        long long ret = calculate();
        cnt[9]        = 0;
        return ret;
    }
    long long ret = 0;
    for (int i = 0; i <= remain; i++) {
        cnt[start] = i;
        ret += dfs(remain - i, start + 1);
        cnt[start] = 0;
    }
    return ret;
}
long long S(long long k) {
    total_length  = k;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        cnt[0] = i;
        ans += dfs(k - i);
    }
    return ans;
}
int main() {
    init();
    cout << S(3) << endl;
    cout << S(12) << endl;
    return 0;
}
