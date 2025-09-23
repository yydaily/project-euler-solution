#include <iostream>
#include <map>
using namespace std;
map<string, int> m; // 1表示必胜, -1表示必败

string to_binary_string(int n) {
    string ret = "";
    while (n) {
        ret += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string filter(string s, int index) {
    string ret = s.substr(0, index) + s.substr(index + 1, s.size());
    while (ret[0] == '0')
        ret = ret.substr(1, ret.size());
    if (ret.length() == 0)
        return "0";
    return ret;
}

int check(int n) {
    auto now = to_binary_string(n);
    if (m.find(now) != m.end())
        return m[now];

    for (int i = 0; i < now.length(); i++) {
        string nxt = filter(now, i);
        if (m[nxt] == -1) {
            return m[now] = 1;
        }
    }
    return m[now] = -1;
}

long long pow9[100];
void init() {
    pow9[0] = 1;
    for (int i = 1; i < 100; i++)
        pow9[i] = pow9[i - 1] * 9;
}

long long W(long long n) {
    m["0"] = -1;
    int x  = -1;
    while (n) {
        x++;
        n /= 10;
    }

    long long ans = 0;
    for (int i = 1; i < (1 << x); i++) {
        if (check(i) == 1) {
            ans += pow9[__builtin_popcount(i)];
        }
    }

    return ans;
}
int main() {
    init();
    cout << W(100) << endl;
    cout << W(1e4) << endl;
    cout << W(1e18) << endl;
    return 0;
}
