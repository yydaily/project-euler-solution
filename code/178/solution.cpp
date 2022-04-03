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

long long cnt[50][11][1050]; // len, tail, acc
int main() {
    for (int i = 1; i <= 9; i++)
        cnt[1][i][1 << i] = 1;
    for (int i = 1; i < 40; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1024; k++) {
                if (j > 0)
                    cnt[i + 1][j - 1][k | 1 << (j - 1)] += cnt[i][j][k];
                if (j < 9)
                    cnt[i + 1][j + 1][k | 1 << (j + 1)] += cnt[i][j][k];
            }
        }
    }
    long long ans = 0;
    for (int i = 10; i <= 40; i++) {
        for (int j = 0; j <= 9; j++) {
            ans += cnt[i][j][1023];
        }
    }
    cout << ans << endl;
    return 0;
}
