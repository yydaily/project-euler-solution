#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <set>
#include <vector>
using namespace std; /*}}}*/
const long long e9 = 1000 * 1000 * 1000;
void spread(vector<int> &dest, int base, int power, int mod) {
    long long now = 1;
    int l         = dest.size();
    for (int i = 1; i <= power; i++) {
        now = (now * base) % mod;
        for (int j = 0; j < l; j++) {
            dest.push_back((dest[j] * now) % mod);
        }
    }
}
void gen(long long base, vector<int> &can_choose, int mod) {
    map<int, int> m;
    for (int i = 2; i * i <= base; i++) {
        while (base % i == 0) {
            base /= i;
            m[i % mod]++;
        }
    }
    if (base != 1)
        m[base % mod]++;

    can_choose.resize(1);
    can_choose[0] = 1;
    for (auto i : m) {
        spread(can_choose, i.first, i.second, mod);
    }

    sort(can_choose.begin(), can_choose.end());
}

long long num[50][4444]; // 选 2^i 个数字，求和 % mod = j 的方案数对 1e9 取模
vector<long long> merge(vector<long long> &old, long long index, long long mod) {
    vector<long long> ret(mod, 0);
    for (int i = 0; i < mod; i++) {
        for (int j = 0; j < mod; j++) {
            long long add      = (num[index][j] * old[i]) % e9;
            long long &updated = ret[(i + j) % mod];
            updated            = (updated + add) % e9;
        }
    }
    return ret;
}
void spread(long long index, long long mod) {
    for (int i = 0; i < mod; i++) {
        for (int j = 0; j < mod; j++) {
            long long add      = (num[index][i] * num[index][j]) % e9;
            long long &updated = num[index + 1][(i + j) % mod];
            updated            = (updated + add) % e9;
        }
    }
}
long long cal(long long cnt, long long mod, long long remind) {
    // 选择 cnt 个数字，每个数字最多选maxm个，求和 % mod = remind, 方案数对 1e9 取模
    vector<long long> origin(mod);
    origin[0] = 1;

    cout << cnt << ' ' << mod << ' ' << remind << endl;
    for (long long i = 0; (1LL << i) <= cnt; i++) {
        if (cnt & (1LL << i)) {
            origin = merge(origin, i, mod);
        }
        spread(i, mod);
    }
    return origin[remind];
}

long long Seq(long long base, long long mod) {
    vector<int> can_choose;
    gen(base, can_choose, mod);
    memset(num, 0, sizeof(num));
    for (auto i : can_choose)
        num[0][i]++;
    return cal(base, mod, mod - base % mod);
}
int main() {
    cout << Seq(3, 4) << endl;
    cout << Seq(4, 11) << endl;
    cout << Seq(1111, 24) << endl;
    cout << Seq(1234567898765, 4321) << endl;
    return 0;
}
