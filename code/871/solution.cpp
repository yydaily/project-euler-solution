#include <iostream>/*{{{*/
#include <set>
using namespace std; /*}}}*/

const int length = 1.1e5;
set<pair<long long, long long>> vis;
set<long long> son[length];
bool choose[length];
int dfs(int a) {
    if (choose[a])
        return 0;
    choose[a] = true;
    int ans   = 1;
    for (auto i : son[a]) {
        if (choose[i])
            continue;
        ans += dfs(i);
    }
    return ans;
}
int D(long long n) {
    vis.clear();
    for (long long i = 0; i < n; i++) {
        son[i].clear();
        choose[i] = false;
    }
    for (long long i = 0; i < n; i++) {
        long long nxt = (i * i * i + i + 1) % n;
        if (nxt == i)
            continue;
        if (vis.count(make_pair(i, nxt))) {
            continue;
        }
        vis.insert(make_pair(i, nxt));
        son[i].insert(nxt);
        son[nxt].insert(i);
    }
    int ans   = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < n; i++) {
            if (son[i].size() == 1) {
                ans++;
                flag    = true;
                int nxt = *son[i].begin();
                for (auto nxt_nxt : son[nxt]) {
                    son[nxt_nxt].erase(nxt);
                }
                son[nxt].clear();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (son[i].size() > 0) {
            int now = dfs(i);
            ans += now / 2;
        }
    }

    return ans;
}

int main() {
    cout << D(5) << endl;
    cout << D(10) << endl;
    long long ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans += D(1e5 + i);
    }
    cout << ans << endl;
    return 0;
}
