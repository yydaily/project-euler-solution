#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
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
long long cal(long long a, long long b) {
    // the index in rows a, columns b
    assert(b <= a);
    long long ret = a * (a - 1) / 2 + b;
    return ret;
}
bool check(long long a, long long b, long long v) {
    // check v is in prime center
    if (!Prime::miller_rabin(v))
        return false;
    // if v is prime, then v-1, v+1 can't be prime
    int cnt = 0;
    for (long long i = max(b - 1, 1LL); i <= b + 1; i++) {
        if (Prime::miller_rabin(cal(a + 1, i)))
            cnt++;
        if (i <= a - 1 && Prime::miller_rabin(cal(a - 1, i)))
            cnt++;
    }
    return cnt >= 2;
}
bool check2(long long a, long long b, long long v) {
    if (!Prime::miller_rabin(v))
        return false;
    // check if v is in Prime triplets
    for (long long i = max(1LL, a - 1); i <= a + 1; i++) {
        for (int j = max(1LL, b - 1); j <= min(b + 1, i); j++) {
            if (check(i, j, cal(i, j)))
                return true;
        }
    }
    return false;
}
long long solve(int a) {
    long long ans = 0;
    long long v   = cal(a, 0);
    int last      = 0;
    for (int i = (v & 1) ^ 1; i <= a; i += 2) { // even number can't be prime, except 2, but I return in advance when a == 2.
        if (i * 100 / a != last) {
            cout << i * 100 / a << endl;
            last = i * 100 / a;
        }
        // cout<<"check("<<a<<", "<<i<<", "<<v+i<<")"<<endl;
        if (check2(a, i, v + i)) {
            ans += v + i;
            // cout<<v+i<<endl;
        }
    }
    cout << "solve(" << a << ") = ";
    return ans;
}
int main() {
    // it cost about 20min to solve it.
    // TODO: use interval sieve to faster this code.
    cout << solve(8) << endl;
    cout << solve(9) << endl;
    cout << solve(10000) << endl;
    cout << solve(5678027) << endl;
    cout << solve(7208785) << endl;
    return 0;
}
