#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}
vector<int> ans[20];
int cal(int a, int b) { return mul(mul(a, b), qpow(add(a, b), mod - 2)); }
void add(int a, int x, int y) {
    for (auto i : ans[x])
        for (auto j : ans[y]) {
            ans[a].push_back(add(i, j));
            ans[a].push_back(cal(i, j));
        }
}
void show() {
    vector<int> a;
    for (int i = 1; i <= 18; i++)
        for (auto j : ans[i])
            a.push_back(j);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << a.size() << endl;
}

int main() {
    ans[1].push_back(1);
    for (int i = 2; i <= 18; i++) {
        for (int j = 1; j * 2 <= i; j++)
            add(i, j, i - j);
        sort(ans[i].begin(), ans[i].end());
        ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end());
    }
    show();
    return 0;
}
