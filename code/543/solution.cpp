#include "../template/prime_cnt.cpp"
#include <iostream>/*{{{*/
#include <math.h>
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
long long num[50];
void init() { /*{{{*/
    num[0] = 0, num[1] = 1;
    for (int i = 2; i <= 44; i++) {
        num[i] = num[i - 1] + num[i - 2];
    }
} /*}}}*/
long long cal(long long a) {
    // f(i, 1) == 1 iff i is a prime
    // part1: prime_cnt where prime <= a
    long long part1 = PrimeCnt::solve(a);

    // f(i, 2) == 1 iff i-2 is prime for odd i, or i is even and >= 4
    long long part2 = PrimeCnt::solve(a - 2) - 1; // odd
    part2 += a / 2 - 1;                           // even

    // f(i, >=3) == 1 iff i>=6
    long long part3 = 0;
    long long copy  = a;
    while (copy / 2 == a / 2) {
        part3 += copy / 2 - 2;
        copy--;
    }
    copy = copy / 2 - 2;
    part3 += (copy + 1) * copy;

    return part1 + part2 + part3;
}
int main() {
    init();
    cout << cal(10) << endl;
    cout << cal(100) << endl;
    cout << cal(1000) << endl;
    long long ans = 0;
    for (int i = 3; i <= 44; i++) {
        long long v = cal(num[i]);
        cout << num[i] << ' ' << v << endl;
        ans += v;
    }
    cout << ans << endl;
    return 0;
}
