#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
const long long mod = 1123455689;
long long jiecheng[20];
int cnt[10];

long long C(int a, int b) {
    if (a < b)
        return 0;
    return jiecheng[a] / jiecheng[b] / jiecheng[a - b] % mod;
}
long long cal() {
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += cnt[i];
    long long ret = 1;
    for (int i = 0; i < 10; i++) {
        ret = ret * C(sum - (i == 0), cnt[i]) % mod;
        sum -= cnt[i];
    }
    return ret;
}
void dfs(long long index, long long need, long long now, long long &ans) {
    if (index == 10) {
        ans = (ans + now * cal()) % mod;
        return;
    }
    long long buf = now;
    for (int i = 0; i <= need; i++) {
        cnt[index] = i;
        dfs(index + 1, need - i, buf, ans);
        cnt[index] = 0;
        buf        = (buf * 10 + index) % mod;
    }
}
long long S(int a) {
    long long ans = 0;
    dfs(0, a, 0, ans);
    return ans;
}
void init() {
    jiecheng[0] = 1;
    for (int i = 1; i < 20; i++)
        jiecheng[i] = jiecheng[i - 1] * i;
}
int main() {
    init();
    cout << S(1) << endl;
    cout << S(5) << endl;
    cout << S(18) << endl;
    return 0;
}
