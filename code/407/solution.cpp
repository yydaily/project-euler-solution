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
const int upper = e7;
int ans[upper + 10];
void merge(vector<long long> &buf, int prime, int cnt) {
    long long now = 1;
    int s         = buf.size();
    for (int i = 1; i <= cnt; i++) {
        now *= prime;
        for (int j = 0; j < s; j++) {
            if (now * buf[j] <= upper)
                buf.push_back(now * buf[j]);
        }
    }
}
void merge(vector<long long> &buf, long long a) {
    while (a != 1) {
        int p   = Prime::max_prime[a];
        int cnt = 0;
        while (a % p == 0) {
            a /= p;
            cnt++;
        }
        merge(buf, p, cnt);
    }
}
void add(long long a) {
    vector<long long> buf;
    buf.push_back(1);
    merge(buf, a);
    merge(buf, a - 1);
    for (auto i : buf)
        if (i > a)
            ans[i] = a;
}
int main() {
    Prime::init(upper + 10);
    for (int i = 2; i < upper; i++)
        ans[i] = 1;
    for (int i = 2; i < upper; i++)
        add(i);
    long long rans = 0;
    for (int i = 1; i <= upper; i++) {
        rans += ans[i];
    }
    cout << ans[6] << endl;
    cout << rans << endl;
    return 0;
}
