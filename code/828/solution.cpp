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
map<pair<int, int>, map<int, string>> cache;
map<int, string> gen(int l, int r) {
    if (l == r) {
        map<int, string> ret;
        ret[d[l]] = to_string(d[l]);
        return ret;
    }
    if (cache[make_pair(l, r)].size() > 0)
        return cache[make_pair(l, r)];
    map<int, string> ret;
    for (int i = l; i < r; i++) {
        auto l_v = gen(l, i);
        auto r_v = gen(i + 1, r);

        for (auto a : l_v) {
            for (auto b : r_v) {
                ret[a.first + b.first] = "(" + a.second + "+" + b.second + ")";
                ret[a.first - b.first] = "(" + a.second + "-" + b.second + ")";
                ret[a.first * b.first] = "(" + a.second + "*" + b.second + ")";
                if (b.first != 0 && a.first % b.first == 0) {
                    ret[a.first / b.first] = "(" + a.second + "/" + b.second + ")";
                }
            }
        }
    }
    ////for(auto i : ret) {
    ////	cout<<i.first<<' '<<i.second<<endl;
    ////}
    cache[make_pair(l, r)] = ret;
    return ret;
}
long long cal() {
    int ans = 1e9;
    string formula;
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
                if (y.first == target) {
                    ans     = buf;
                    formula = y.second;
                    break;
                }
            }
        }
    } while (next_permutation(d, d + 6));
    if (ans == 1e9) {
        return 0;
    }
    cout << ans << ":" << target << " = " << formula << endl;
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
