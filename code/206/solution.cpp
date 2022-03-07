#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int num[8];
bool check() {
    long long now = 1;
    for (int i = 0; i < 8; i++) {
        now = now * 100 + num[i] * 10 + i + 2;
    }
    long long x = sqrt(now);
    if (x * x == now) {
        cout << x * 10 << endl;
        return true;
    }
    return false;
}
int main() {
    while (true) {
        num[0]++;
        int ind = 0;
        while (num[ind] >= 10) {
            num[ind] -= 10;
            num[++ind]++;
        }
        if (check())
            break;
    }
    return 0;
}
