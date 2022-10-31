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
int mod            = 998244353;
using namespace std; /*}}}*/
inline int add(int a, int b) {
    a += b;
    return a - (a >= mod ? mod : 0);
}
int dp[3][3][2048][3][3][1024];
int n     = 100;
int upper = 2 * n; // upper 对
void push_back(int _, int __, int ind, int dir1, int dir2, int cnt) {
    int last = dp[_][__][ind][dir1][dir2][cnt];
    for (int new_dir1 = 0; new_dir1 < 3; new_dir1++) {
        for (int new_dir2 = 0; new_dir2 < 3; new_dir2++) {
            int now = cnt;
            if (dir1 == 1 && new_dir1 == 0)
                now++;
            if (dir2 == 1 && new_dir2 == 0)
                now++;
            if (new_dir1 == 2 && new_dir2 == 2)
                now++;
            if (now > 1000)
                continue;
            dp[_][__][ind + 1][new_dir1][new_dir2][now] = add(dp[_][__][ind + 1][new_dir1][new_dir2][now], last);
        }
    }
}
int main() {
    // 方向分别为，左，右，对面
    int ans = 0;
    for (int first_dir = 0; first_dir < 3; first_dir++) {
        for (int second_dir = 0; second_dir < 3; second_dir++) {
            dp[first_dir][second_dir][1][first_dir][second_dir][first_dir == 2 && second_dir == 2] = 1;
            for (int i = 1; i < upper; i++) {
                for (int last_dir = 0; last_dir < 3; last_dir++) {
                    for (int last_dir2 = 0; last_dir2 < 3; last_dir2++) {
                        for (int cnt = 0; cnt <= n; cnt++) {
                            push_back(first_dir, second_dir, i, last_dir, last_dir2, cnt);
                        }
                    }
                }
            }
            for (int dir1 = 0; dir1 < 3; dir1++) {
                for (int dir2 = 0; dir2 < 3; dir2++) {
                    int add_cnt = 0;
                    if (second_dir == 0 && dir1 == 1)
                        add_cnt++;
                    if (first_dir == 0 && dir2 == 1)
                        add_cnt++;
                    ans = add(ans, dp[first_dir][second_dir][upper][dir1][dir2][n - add_cnt]);
                }
            }
            cout << first_dir << ' ' << second_dir << ' ' << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
