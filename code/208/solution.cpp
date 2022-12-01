#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
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
struct p {
    int cnt[5];
    int dir;
    double x, y;
    const bool operator<(const p &a) const {
        if (fabs(x - a.x) > 1e-6)
            return x < a.x;
        if (fabs(y - a.y) > 1e-6)
            return y < a.y;
        return false;
    }
};
map<p, long long> pre;

void spread(p a, vector<p> &ret) {
    // l
    p b;
    for (int i = 0; i < 5; i++)
        b.cnt[i] = a.cnt[i];
    b.dir = (a.dir + 72) % 360;
    b.cnt[a.dir / 72]++;
    auto angle = (a.dir + 36) * 1.0 / 180 * acos(-1);
    b.x        = a.x + cos(angle);
    b.y        = a.y + sin(angle);
    ret.push_back(b);

    // r
    p c;
    for (int i = 0; i < 5; i++)
        c.cnt[i] = a.cnt[i];
    c.dir = (a.dir + 360 - 72) % 360;
    c.cnt[(a.dir / 72 + 4) % 5]++;
    angle = (a.dir + 360 - 72) % 360 * 1.0 / 180 * acos(-1);
    c.x   = a.x + cos(angle);
    c.y   = a.y + sin(angle);
    ret.push_back(c);
}
map<p, long long> spread() {
    map<p, long long> now;
    for (auto i : pre) {
        vector<p> nxt;
        spread(i.first, nxt);
        now[nxt[0]] += i.second;
        now[nxt[1]] += i.second;
    }
    return now;
}
int main() {
    p origin;
    memset(origin.cnt, 0, sizeof(origin.cnt));
    origin.dir = 0;
    origin.x   = 0;
    origin.y   = 0;

    pre[origin] = 1;
    for (int i = 1; i <= 70; i++) {
        pre = spread();
    }
    cout << pre[origin] << endl;
    return 0;
}
