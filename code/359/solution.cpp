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

void show(__int128 a, char x = '\n') {
    long long s = a % e8;
    cout << s << x;
}

bool check(__int128 a) {
    __int128 b = sqrt(a);
    return b * b == a;
}

__int128 start(__int128 a) {
    if (a == 1)
        return 1;
    __int128 ret = 2 * (a / 2) * (a / 2);
    if (a & 1)
        ret += 2 * (a / 2);
    return ret;
}

__int128 nxt(__int128 a) {
    __int128 b = sqrt(2 * a);
    while (b * b - a <= a)
        b++;
    return b * b - a;
}

__int128 cal(__int128 row, __int128 column) {
    __int128 a0 = start(row);
    __int128 a1 = nxt(a0);
    __int128 b  = sqrt(a1 + a0);
    column--;
    __int128 x   = column / 2;
    __int128 ret = a0 + x * (2 * b + 2 * x - 1);
    if (column & 1)
        ret = nxt(ret);
    return ret;
}

__int128 ans(int a, int b) {
    // 2^a * 3^b
    __int128 upper = 1;
    for (int i = 1; i <= a; i++)
        upper *= 2;
    for (int i = 1; i <= b; i++)
        upper *= 3;

    __int128 rans = 0;

    __int128 x = 1;
    for (int i = 0; i <= a; i++) {
        __int128 y = x;
        for (int j = 0; j <= b; j++) {
            rans += cal(y, upper / y);
            y *= 3;
        }
        x *= 2;
    }
    return rans;
}

int main() {
    ////show(cal(10, 20));
    ////show(cal(25, 75));
    ////show(cal(99, 100));
    show(ans(27, 12));
    return 0;
}
