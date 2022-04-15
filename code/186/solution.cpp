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
const int root = 524287;
const int mod  = e6;
int pre[mod];
int cnt[mod];
int val[e4];
int find(int a) { /*{{{*/
    if (pre[a] == a)
        return a;
    pre[a] = find(pre[a]);
    return pre[a];
} /*}}}*/
bool merge(int a, int b) { /*{{{*/
    if (a == b)
        return true;
    int aa = find(a);
    int bb = find(b);
    if (aa == bb)
        return false;
    pre[bb] = aa;
    cnt[aa] += cnt[bb];
    return false;
} /*}}}*/
long long get(long long index) {
    if (index <= 55) {
        val[index] = (100003 - 200003 * index + 300007 * index * index * index) % mod;
    } else {
        val[index % e4] = (val[(index + e4 - 24) % e4] + val[(index - 55 + e4) % e4]) % mod;
    }
    return val[index % e4];
}
int main() {
    for (int i = 0; i < mod; i++) {
        pre[i] = i;
        cnt[i] = 1;
    }
    int ans = 0;
    for (int i = 1;; i++) {
        int a = get((i << 1) - 1);
        int b = get(i << 1);
        if (merge(a, b)) {
            ans--;
        }
        if (cnt[find(root)] >= mod / 100 * 99) {
            cout << i + ans << endl;
            break;
        }
    }
    return 0;
}
