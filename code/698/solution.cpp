#include <iostream>/*{{{*/
#include <vector>
using namespace std; /*}}}*/
int x[] = {0, 1, 2, 3, 11, 12, 13, 21, 22, 23, 31, 32, 33, 111};
long long C(long long a, long long b) {
    long long ret = 1;
    for (int i = 1; i <= b; i++) {
        ret = ret * (a - b + i) / i;
    }
    return ret;
}

long long cal(long long a, long long b, long long c) { return C(a + b + c, a) * C(b + c, min(b, c)); }

vector<vector<int>> v;

long long cal(int len) {
    long long ret = 0;
    v.clear();
    for (int i = 0; x[i] <= len; i++) {
        for (int j = 0; x[i] + x[j] <= len; j++) {
            for (int k = 0; x[i] + x[j] + x[k] <= len; k++) {
                if (x[i] + x[j] + x[k] != len)
                    continue;
                ret += cal(x[i], x[j], x[k]);
                vector<int> buf(3);
                buf[0] = x[i];
                buf[1] = x[j];
                buf[2] = x[k];
                v.push_back(buf);
            }
        }
    }
    return ret;
}

long long solve(long long index, long long length, long long mod) {
    long long ret = 0;
    int cnt[3]    = {0, 0, 0};
    for (int i = 0; i < length; i++) {
        for (int j = 1; j <= 3; j++) {
            cnt[j - 1]++;
            long long solutions = 0;
            for (auto a : v) {
                if (a[0] < cnt[0] || a[1] < cnt[1] || a[2] < cnt[2])
                    continue;
                solutions += cal(a[0] - cnt[0], a[1] - cnt[1], a[2] - cnt[2]);
            }
            cnt[j - 1]--;

            if (solutions < index) {
                index -= solutions;
            } else {
                cnt[j - 1]++;
                ret = (ret * 10 + j) % mod;
                break;
            }
        }
    }
    return ret;
}

long long F(long long index, long long mod = 1000000000000037) {
    if (index <= 12)
        return x[index];
    index -= 12;
    for (int len = 3;; len++) {
        long long now = cal(len);
        if (index > now) {
            index -= now;
            continue;
        }
        return solve(index, len, mod);
    }
    return -1;
}
int main() {
    cout << F(4) << endl;
    cout << F(10) << endl;
    cout << F(40) << endl;
    cout << F(1000) << endl;
    cout << F(6000) << endl;
    cout << F(111111111111222333, 123123123) << endl;
    return 0;
}
