#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
const long long e2 = 100;
const long long e3 = e2 * 10;
const long long e4 = e3 * 10;
const long long e5 = e4 * 10;
const long long e6 = e4 * e2;
const long long e7 = e6 * 10;
const long long e8 = e7 * 10;
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
using namespace std; /*}}}*/
const long long upper = 1e12;
int main() {
    Prime::init(e6);
    long long ans = 0;
    // p^7 <= 1e12  -->  p <= 51
    ans += PrimeCnt::solve(pow(upper, 1.0 / 7));
    cout << ans << endl;
    // p1 * p2^3
    int s = Prime::prime.size();
    for (int i = 0; i < s; i++) { /*{{{*/
        long long p2  = Prime::prime[i];
        long long p23 = p2 * p2 * p2;
        if (p23 > upper)
            break;
        long long cnt = PrimeCnt::solve(upper / p23);
        if (cnt >= i + 1)
            cnt--; // p1 == p2
        ans += cnt;
    } /*}}}*/
    cout << ans << endl;
    // p1 * p2 * p3
    /*{{{*/
    for (int a = 0; a < s; a++) {
        long long p1 = Prime::prime[a];
        for (int b = a + 1; b < s; b++) {
            long long p2 = Prime::prime[b];
            if (p1 * p2 > upper)
                break;
            long long cnt = PrimeCnt::solve(upper / p1 / p2);
            if (cnt <= b + 1)
                break;
            ans += cnt - b - 1;
        }
    } /*}}}*/
    cout << ans << endl;
    return 0;
}
