#include "../template/progress_rate.cpp"
#include <iostream>/*{{{*/
#include <stack>
using namespace std; /*}}}*/
typedef long long ll;
ll d[10000000 + 10];
ll d2[10000000 + 10];
ll solve(int len) {
    stack<pair<int, int>> s;
    s.push(make_pair(0, 1));
    long long now = 290797;
    for (int i = 1; i <= len; i++) {
        d[i]            = now;
        long long value = now;
        long long cnt   = 1;
        while (value / cnt < s.top().first) {
            auto x = s.top();
            s.pop();
            value += x.first * x.second;
            cnt += x.second;
        }

        ll cnt1 = value % cnt;
        s.push(make_pair(value / cnt, cnt - cnt1));
        if (cnt1) {
            s.push(make_pair(value / cnt + 1, cnt1));
        }

        now = (now * now) % 50515093;
    }

    for (int i = len; i >= 1;) {
        auto x = s.top();
        s.pop();
        for (int j = 0; j < x.second; j++) {
            d2[i - j] = x.first;
        }
        i -= x.second;
    }

    long long ans = 0;
    for (int i = 1; i <= len; i++) {
        if (d2[i] == d[i])
            continue;
        ans += d[i] - d2[i];
        d[i + 1] += d[i] - d2[i];
    }
    return ans;
}
int main() {
    cout << solve(5) << endl;
    cout << solve(6) << endl;
    cout << solve(100) << endl;
    cout << solve(1e7) << endl;
    return 0;
}
