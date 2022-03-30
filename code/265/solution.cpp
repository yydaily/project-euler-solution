#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
using namespace std; /*}}}*/

const int need     = 5;
const string start = "00000";

bool check(int a, int b) {
    b >>= 1;
    for (int i = 1; i < need; i++) {
        if ((a & 1) != (b & 1))
            return false;
        a >>= 1;
        b >>= 1;
    }
    return true;
}
vector<int> son[40];
bool vis[40];

int cal(int ind, string &a) {
    int ret = 0;
    for (int i = 0; i < need; i++) {
        if (a[ind + i] == '1')
            ret += (1 << (need - i - 1));
    }
    return ret;
}
bool ok(string &now) {
    bool v[40];
    memset(v, false, sizeof(v));
    for (int i = 0; i < (1 << need); i++) {
        int vv = cal(i, now);
        if (v[vv])
            return false;
        v[vv] = true;
    }
    return true;
}

long long ans = 0;
void dfs(int a = 0, string now = start) {
    if (now.length() == (1 << need)) {
        if (!ok(now))
            return;
        int v = 0;
        for (int i = 0; i < now.length(); i++) {
            if (now[i] == '1')
                v = v << 1 | 1;
            else
                v = v << 1;
        }
        ans += v;
        return;
    }
    for (auto i : son[a]) {
        if (vis[i])
            continue;
        vis[i] = true;
        dfs(i, now + to_string(i & 1));
        vis[i] = false;
    }
}
int main() {
    for (int i = 0; i < (1 << need); i++) {
        for (int j = 0; j < (1 << need); j++) {
            if (j == i)
                continue;
            if (check(i, j)) {
                son[i].push_back(j);
            }
        }
    }
    vis[0] = true;
    dfs();
    cout << ans << endl;
    return 0;
}
