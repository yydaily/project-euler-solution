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
#include <utility>
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

const __int128 n     = 61;
const __int128 upper = 10000000;
const __int128 mod   = 713342911662882601;
inline __int128 add(__int128 a, __int128 b) { return (a + b) % mod; }
inline __int128 mul(__int128 a, __int128 b) { return a * b % mod; }
__int128 s[upper + 1];
__int128 pown[upper + 1];
void init_s() {
    s[0]    = 290797;
    pown[0] = 1;
    for (int i = 1; i <= upper; i++) {
        s[i] = s[i - 1] * s[i - 1] % 50515093;
        s[i - 1] %= n;
        pown[i] = mul(pown[i - 1], n);
    }
    s[upper] %= n;
}
__int128 NF() {
    __int128 ans = 0;
    for (int i = upper; i >= 1; i--) {
        ans      = add(ans, mul(s[i], pown[i - 1]));
        s[i - 1] = add(s[i - 1], s[i]);
    }
    return ans;
}
int main() {
    init_s();
    long long ans = NF();
    cout << ans << endl;
    return 0;
}
