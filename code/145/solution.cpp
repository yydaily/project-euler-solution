#include <iostream>
using namespace std;
int rev(unsigned int a) {
    unsigned int ret = 0;
    while (a > 0) {
        ret = ret * 10 + a % 10;
        a /= 10;
    }
    return ret;
}

int check(unsigned int a) {
    if (a % 10 == 0)
        return 0;
    a += rev(a);
    while (a > 0) {
        if (a % 2 == 0)
            return 0;
        a /= 10;
    }
    return 1;
}

int main() {
    int upper = 1000 * 1000 * 100;
    int ans   = 0;
    for (int i = 1; i <= upper; i += 2)
        if (check(i))
            ans++;
    cout << (ans << 1) << endl;
    return 0;
}
