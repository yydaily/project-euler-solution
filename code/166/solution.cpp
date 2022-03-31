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

int num[4][4];
int main() {
    long long cnt = 0;
    for (int i = 0; i < e9; i++) {
        int c = i;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++) {
                num[x][y] = c % 10;
                c /= 10;
            }
        int maxm = 0, minm = 40;
        for (int x = 0; x < 3; x++) {
            int now = 0;
            for (int y = 0; y < 3; y++)
                now += num[x][y];
            maxm = max(maxm, now);
            minm = min(minm, now);
            now  = 0;
            for (int y = 0; y < 3; y++)
                now += num[y][x];
            maxm = max(maxm, now);
            minm = min(minm, now);
        }
        if (minm + 9 < maxm)
            continue;
        for (int sum = maxm; sum <= minm + 9; sum++) {
            for (int x = 0; x < 3; x++) {
                num[x][3] = sum - num[x][0] - num[x][1] - num[x][2];
                num[3][x] = sum - num[0][x] - num[1][x] - num[2][x];
            }
            num[3][3] = sum - num[0][3] - num[1][3] - num[2][3];
            if (num[3][3] < 0 || num[3][3] > 9)
                continue;
            if (num[0][0] + num[1][1] + num[2][2] + num[3][3] != sum)
                continue;
            num[3][3] = sum - num[0][3] - num[1][3] - num[2][3];
            if (num[0][3] + num[1][2] + num[2][1] + num[3][0] != sum)
                continue;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
