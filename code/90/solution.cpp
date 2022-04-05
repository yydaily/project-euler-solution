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

struct p { /*{{{*/
    int num[6];
    p(){};
    p(int a) {
        for (int i = 0; i < 6; i++) {
            num[i] = a % 10;
            a /= 10;
        }
    }
    bool gen() {
        sort(num, num + 6);
        for (int i = 1; i < 6; i++)
            if (num[i] == num[i - 1])
                return false;
        return true;
    }
    bool operator<(const p &a) const {
        for (int i = 0; i < 6; i++)
            if (num[i] != a.num[i])
                return num[i] < a.num[i];
        return false;
    }
}; /*}}}*/
map<int, bool> vis;
void add(int a, int b) { /*{{{*/
    vis[a * 10 + b] = true;
    vis[b * 10 + a] = true;
    if (a == 6 || a == 9) {
        a               = 15 - a;
        vis[a * 10 + b] = true;
        vis[b * 10 + a] = true;
    }
    if (b == 6 || b == 9) {
        b               = 15 - b;
        vis[a * 10 + b] = true;
        vis[b * 10 + a] = true;
    }
} /*}}}*/
bool check(p &a, p &b) {
    vis.clear();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            add(a.num[i], b.num[j]);
        }
    }
    for (int i = 1; i <= 9; i++)
        if (!vis[i * i])
            return false;
    return true;
}
int main() {
    set<p> v;
    for (int i = 12345; i <= 987654; i++) {
        auto now = p(i);
        if (now.gen())
            v.insert(now);
    }
    int ans = 0;
    for (auto i : v) {
        for (auto j : v) {
            if (i < j)
                continue;
            if (check(i, j))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
