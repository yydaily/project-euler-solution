#include <iostream>
#include <vector>
using namespace std;
void gen(long long &n, long long &t) {
    auto nn = -9 * n - 4 * t - 2;
    t       = -20 * n - 9 * t - 4;
    n       = nn;
}
vector<long long> ans;
void get(long long n, long long t) {
    for (int i = 1; i <= 12; i++) {
        gen(n, t);
        if (n > 0)
            ans.push_back(n);
    }
}
int main() {
    get(0, -1);
    get(0, 1);
    get(-1, -2);
    sort(ans.begin(), ans.end());
    cout << ans[14] << endl;
    return 0;
}
