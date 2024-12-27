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
long double a = 2;
long double b = 3;
map<long long, long double> cost;
long long ans[1000][1000];
typedef struct p {
    int cnt_a;
    int cnt_b;
    long double dis;
    p() {};
    p(int cnt_a_, int cnt_b_, long double dis_) : cnt_a(cnt_a_), cnt_b(cnt_b_), dis(dis_) {};
} poi;
bool cmp(const poi &a, const poi &b) { return a.dis < b.dis; }
long double C(long long length) {
    vector<poi> v;
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 200; j++) {
            v.push_back(poi(i, j, i * a + j * b));
        }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++) {
        long long l = 0, r = 0;
        long double dis_now = v[i].dis - a;
        for (auto j : v) { // 这里其实不用便利，应该开个order_set，或者二分查找，可以优化到log，但是即使循环本身也很快了，所以没有优化
            if (j.dis - 1e-12 <= dis_now) {
                l = max(l, ans[j.cnt_a][j.cnt_b]);
            } else
                break;
        }

        dis_now = v[i].dis - b;
        for (auto j : v) {
            if (j.dis - 1e-12 <= dis_now) {
                r = max(r, ans[j.cnt_a][j.cnt_b]);
            } else
                break;
        }
        ans[v[i].cnt_a][v[i].cnt_b] = 1 + l + r;
        if (ans[v[i].cnt_a][v[i].cnt_b] >= length)
            return v[i].dis;
    }
    return -1;
}
long double C(long long length, long double a_, long double b_) {
    a = a_;
    b = b_;
    if (a > b)
        swap(a, b);
    return C(length);
}

int main() {
    long long F[31] = {0, 1};
    long double ans = C(1e12, 1, 1);
    for (int i = 2; i <= 30; i++) {
        F[i] = F[i - 1] + F[i - 2];
        ans += C(1e12, sqrt(i), sqrt(F[i]));
    }
    printf("%.8LF\n", ans);
    return 0;
}
