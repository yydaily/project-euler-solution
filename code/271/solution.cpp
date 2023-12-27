#include "../template/china_reminder.cpp"
#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <vector>
using namespace std; /*}}}*/
// 13082761331670030 = 2*3*5*7*11*13*17*19*23*29*31*37*41*43
vector<int> v[100];
map<int, int> m;

long long ans = 0;

void dfs(int now = 2) {
    for (auto i : v[now]) {
        m[now] = i;

        if (now == 43) {
            ChinaReminder::clear();
            for (auto p : Prime::prime) {
                ChinaReminder::add(m[p], p);
            }
            ans += ChinaReminder::China() % 13082761331670030LL;
            continue;
        }

        for (auto p : Prime::prime) {
            if (p > now) {
                dfs(p);
                break;
            }
        }
    }
}
int main() {
    Prime::init(45);
    for (auto i : Prime::prime) {
        for (int j = 1; j < i; j++) {
            if (j * j * j % i == 1) {
                v[i].push_back(j);
            }
        }
    }

    dfs();
    cout << ans - 1 << endl;
    return 0;
}
