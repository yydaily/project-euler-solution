#include <iostream>/*{{{*/
#include <map>
#include <vector>
using namespace std; /*}}}*/

long long mod = 1000062031;

long long qpow(long long a, long long b) {
    if (b <= 0)
        return 1;
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void format(map<long long, int> &m, long long index) {
    while (m[index] >= 2) {
        m[index] -= 2;
        if (m[index] == 0) {
            m.erase(index);
        }
        m[++index]++;
    }
}

vector<long long> H(long long t, long long r) {
    vector<long long> ret(1);
    ret[0] = 0;

    for (int i = 0; i < r; i++) {
        map<long long, int> m;
        for (auto x : ret) {
            m[x]++;
            m[x + t]++;
            format(m, x);
            format(m, x + t);
        }

        ret.resize(m.size());
        int index = 0;
        for (auto x : m) {
            ret[index++] = x.first;
        }
    }
    return ret;
}

int main() {
    long long b = 1e14 + 31;
    long long p = 62;

    long long ans           = 1;
    vector<long long> index = H(b, p);

    long long base = 1;
    for (int i = index.size() - 1; i >= 1; i--) {
        base = (3 + base * 5) % mod;
        while (index[i - 1] == index[i] - 1) {
            i--;
            base = (3 + base * 5) % mod;
        }
        ans = ans * (qpow(base, index[i] - index[i - 1] - 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}
