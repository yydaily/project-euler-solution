#include <iostream>
#include <map>
using namespace std;
int cal(int a) {
    int base = 1;
    int ans  = 0;
    map<int, int> m;
    while (base) {
        base = (base * 10) % a;
        if (m[base])
            return ans - m[base] + 1;
        m[base] = ++ans;
        if (base == 1)
            return ans;
    }
    return 0;
}
int main() {
    int ans = 1;
    for (int i = 3; i < 1000; i++) {
        if (cal(i) > cal(ans)) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
