#include <algorithm>
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
long long _mod = 1005075251;
using namespace std; /*}}}*/
int target;
int d[6];
map<pair<int, int>, vector<int>> cache;
vector<int> gen(int l, int r) {
    if (l == r)
        return vector<int>(1, d[l]);
    if (cache[make_pair(l, r)].size() > 0)
        return cache[make_pair(l, r)];
    set<int> s;
    for (int i = l; i < r; i++) {
        auto l_v = gen(l, i);
        auto r_v = gen(i + 1, r);

        for (auto a : l_v) {
            for (auto b : r_v) {
                s.insert(a + b);
                s.insert(a - b);
                s.insert(a * b);
                if (b != 0 && a % b == 0)
                    s.insert(a / b);
            }
        }
    }
    vector<int> ret;
    for (auto i : s) {
        ret.push_back(i);
    }
    cache[make_pair(l, r)] = ret;
    return ret;
}
long long cal() {
    int ans = 1e9;
    sort(d, d + 6);
    do {
        cache.clear();
        int buf = 0;
        for (int i = 0; i < 6; i++) {
            buf += d[i];
            if (buf > ans)
                break;
            auto x = gen(0, i);
            for (auto y : x) {
                if (y == target) {
                    ans = buf;
                    break;
                }
            }
        }
    } while (next_permutation(d, d + 6));
    if (ans == 1e9) {
        return 0;
    }
    cout << ans << endl;
    return ans;
}
int main() {
    freopen("./data", "r", stdin);
    long long power = 1;
    long long ans   = 0;
    while (scanf("%d:", &target) != EOF) {
        for (int i = 0; i < 5; i++)
            scanf("%d,", &d[i]);
        scanf("%d", &d[5]);
        power = (power * 3) % _mod;
        ans   = (ans + power * cal()) % _mod;
    }
    cout << ans << endl;
    return 0;
}
