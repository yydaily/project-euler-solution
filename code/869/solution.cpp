#include "../template/bigint.cpp"
#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <math.h>
using namespace std; /*}}}*/
long long len(int a) {
    long long ret = 0;
    while (a) {
        ret++;
        a /= 2;
    }
    return ret;
}
long long solve(vector<int> &buf, string indent = "") {
    if (buf.size() == 0)
        return 0;
    if (buf.size() == 1)
        return len(buf[0]);
    int cnt1 = 0;
    vector<int> buf0, buf1;
    for (auto i : buf) {
        if (i == 1) {
            cnt1++;
            continue;
        }
        if (i & 1) {
            cnt1++;
            buf1.push_back(i >> 1);
        } else {
            buf0.push_back(i >> 1);
        }
    }

    long long ans = (cnt1 > buf.size() - cnt1) ? cnt1 : (buf.size() - cnt1);
    ans += solve(buf1) + solve(buf0);
    return ans;
}
int main() {
    Prime::init(1e8);
    vector<int> buf;
    for (auto i : Prime::prime) {
        buf.push_back(i);
    }
    cout << fixed << setprecision(8) << round(solve(buf) * 100) / 100 / Prime::prime.size() << endl;
    return 0;
}
