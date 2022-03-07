#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 1, b = 2;
    int sum = 0;
    while (b < 4 * 1000 * 1000) {
        if (b % 2 == 0)
            sum += b;
        swap(a, b);
        b += a;
    }
    cout << sum << endl;
    return 0;
}
