#include <iostream>
using namespace std;
bool check(long long x) {
    string z    = to_string(x * x);
    long long a = 0, b = 0;
    if (z[z.size() / 2] == '0')
        return false;
    for (int i = 0; i < z.size() / 2; i++) {
        a = a * 10 + z[i] - '0';
    }
    for (int i = z.size() / 2; i < z.size(); i++) {
        b = b * 10 + z[i] - '0';
    }
    return a + b == x;
}
int main() {
    long long ans = 0;
    for (long long i = 9; i < 1e8; i++) {
        if (check(i)) {
            ans += i * i;
        }
    }
    cout << ans << endl;
    return 0;
}
