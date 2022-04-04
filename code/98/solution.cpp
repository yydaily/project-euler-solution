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
vector<string> s[50];
bool match(string a, string b) { /*{{{*/
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
} /*}}}*/
int cal(string a, long long v) { /*{{{*/
    map<char, int> m;
    bool match = true;
    bool vis[10];
    memset(vis, false, sizeof(vis));
    for (int i = a.length() - 1; i >= 0; i--) {
        if (v == 0) {
            return 0;
        }
        if (m[a[i]]) {
            if (v % 10 + 100 != m[a[i]])
                match = false;
            v /= 10;
            continue;
        }
        if (vis[v % 10]) {
            return 0;
        }
        vis[v % 10] = true;
        m[a[i]]     = v % 10 + 100;
        v /= 10;
    }
    if (v)
        return -1;
    if (match)
        return 1;
    return 0;
} /*}}}*/
long long cal(string a, string b, long long v) { /*{{{*/
    map<char, int> m;
    for (int i = a.length() - 1; i >= 0; i--) {
        m[a[i]] = v % 10;
        v /= 10;
    }
    if (m[b[0]] == 0)
        return 2; // 排除前导0
    long long ret = 0;
    for (int i = 0; i < b.length(); i++) {
        ret = ret * 10 + m[b[i]];
    }
    return ret;
} /*}}}*/
long long cal(string a, string b) { /*{{{*/
    long long ret = 0;
    for (long long i = 1;; i++) {
        int v = cal(a, i * i);
        if (v == 0)
            continue;
        if (v == -1)
            return ret;
        if (v == 1) {
            long long vv  = cal(a, b, i * i);
            long long vvv = sqrt(vv);
            if (vvv * vvv == vv) {
                cout << a << ' ' << b << ' ' << i * i << ' ' << vv << endl;
                ret = max(ret, max(i * i, vv));
            }
        }
    }
    return ret;
} /*}}}*/
long long cal(int length) { /*{{{*/
    long long ans = 0;
    for (int i = 0; i < s[length].size(); i++) {
        for (int j = i + 1; j < s[length].size(); j++) {
            if (!match(s[length][i], s[length][j]))
                continue;
            long long v = cal(s[length][i], s[length][j]);
            // cout<<s[length][i]<<' '<<s[length][j]<<' '<<v<<endl;
            ans = max(ans, v);
        }
    }
    return ans;
} /*}}}*/
int main() { /*{{{*/
    freopen("./in", "r", stdin);
    string a;
    while (cin >> a)
        s[a.length()].push_back(a);
    long long ans = 0;
    for (int i = 1; i < 50; i++) {
        if (s[i].size() < 2)
            continue;
        ans = max(ans, cal(i));
    }
    cout << ans << endl;
    return 0;
} /*}}}*/
