#include "../template/prime.cpp"
#include <iostream>/*{{{*/
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = 1000 * 1000;
using namespace std; /*}}}*/
long long cal(long long a) {
    long long ret = 0;
    if (a % 2 == 0)
        return ret;
    long long x = (a + 13) / 2;
    return ret + 2 * max(0LL, ((x - 3) / 4 - x % 3) / 3);
}
int main() {
    Prime::init(e6);
    long long ans = 0;
    for (auto i : Prime::prime) {
        if (i < e6)
            ans += cal(1LL * i * i);
        else
            break;
    }
    cout << ans + 2 << endl;
    return 0;
}
