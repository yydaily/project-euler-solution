#include <iostream>

using namespace std;
int ans[100];
int main() {
    freopen("./in", "r", stdin);
    string a;
    while (cin >> a) {
        reverse(a.begin(), a.end());
        for (int i = 0; i < a.length(); i++)
            ans[i] += a[i] - '0';
    }
    for (int i = 0; i < 99; i++) {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    int ind = 0;
    for (int i = 99; i >= 0; i--)
        if (ans[i]) {
            ind = i;
            break;
        }
    for (int i = ind; i > ind - 10; i--)
        cout << ans[i];
    cout << endl;
    return 0;
}
