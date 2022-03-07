#include <iostream>
using namespace std;
bool check(int a) {
    int t[3] = {1, 1, 1};
    while (true) {
        int tar = (t[0] + t[1] + t[2]) % a;
        if (tar == 0)
            return false;
        t[0] = t[1];
        t[1] = t[2];
        t[2] = tar;
        if (t[0] == t[1] && t[1] == t[2] && t[2] == 1)
            return true;
    }
    return true;
}
int main() {
    int cnt = 0;
    for (int i = 27;; i += 2) {
        if (check(i))
            cnt++;
        if (cnt == 124) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
