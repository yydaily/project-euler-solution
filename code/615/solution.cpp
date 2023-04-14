#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <math.h>
#include <set>
using namespace std; /*}}}*/
const long long mod = 123454321;
struct poi {
    int cnt_2;
    double now;
    poi(int _c = 0, double _n = 0) {
        cnt_2 = _c;
        now   = _n;
    }
    bool operator<(const poi &a) const {
        int diff_2 = cnt_2 - a.cnt_2;
        double l   = now * pow(2, diff_2);
        return l < a.now;
    }
};
void clear(set<poi> &s, int need_cnt) {
    while (s.size() > need_cnt) {
        auto x = s.end();
        x--;
        s.erase(x);
    }
}
long long solve(int need_cnt, int length) {
    set<poi> s;
    for (int i = 0; i < need_cnt; i++)
        s.insert(poi(length + i, 1));
    for (auto i : Prime::prime) {
        if (i == 2)
            continue;
        auto x = s.end();
        x--;

        double now = i;
        int cnt    = 1;
        set<poi> added;
        while (cnt <= 30 && poi(s.begin()->cnt_2 - cnt, s.begin()->now * now) < *x) {
            for (auto pre : s) {
                auto buf = poi(pre.cnt_2 - cnt, pre.now * now);
                if (*x < buf)
                    break;
                added.insert(buf);
                clear(added, need_cnt);
            }
            now *= i;
            cnt++;
        }

        if (added.size() == 0)
            break;

        for (auto i : added)
            s.insert(i);

        clear(s, need_cnt);
    }

    auto x = s.end();
    x--;

    long long now = x->now;
    int cnt       = x->cnt_2;
    while (cnt > 0) {
        cnt--;
        now = now * 2 % mod;
    }
    return now;
}

int main() {
    Prime::init(1e6);
    cout << solve(5, 5) << endl; // 80
    cout << solve(5, 6) << endl; // 160
    cout << solve(6, 5) << endl; // 96
    cout << solve(1e6, 1e6) << endl;
    return 0;
}
