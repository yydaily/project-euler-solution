#include <iostream>
#include <map>
using namespace std;
const long long mod = 987654321;
const int sg_cnt    = 64;
struct matrix {
    long long d[sg_cnt][sg_cnt];
};
matrix mul(matrix a, matrix b) {
    matrix ret;
    memset(ret.d, 0, sizeof(ret.d));
    for (int i = 0; i < sg_cnt; i++) {
        for (int j = 0; j < sg_cnt; j++) {
            for (int k = 0; k < sg_cnt; k++) {
                ret.d[i][k] = (ret.d[i][k] + a.d[i][j] * b.d[j][k] % mod) % mod;
            }
        }
    }
    return ret;
}
matrix qpow(matrix a, long long power) {
    matrix ret;
    memset(ret.d, 0, sizeof(ret.d));
    for (int i = 0; i < sg_cnt; i++)
        ret.d[i][i] = 1;

    while (power) {
        if (power & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        power >>= 1;
    }
    return ret;
}

long long cal(map<int, int> m, long long power) {
    matrix start;
    memset(start.d, 0, sizeof(start.d));

    for (int i = 0; i < sg_cnt; i++) {
        for (auto j : m) {
            start.d[i][i ^ j.first] = (start.d[i][i ^ j.first] + j.second) % mod;
        }
    }

    start         = qpow(start, power);
    long long ans = 0;
    for (int i = 1; i < sg_cnt; i++) {
        ans = (ans + start.d[0][i]) % mod;
    }
    return ans;
}
int main() {
    map<int, int> m1;
    m1[0] = m1[1] = 4;
    m1[2]         = 1;
    cout << cal(m1, 5) << endl;

    map<int, int> m2;
    m2[0]  = 664579;
    m2[1]  = 1904324;
    m2[2]  = 2444359;
    m2[4]  = 2050696;
    m2[7]  = 1349779;
    m2[8]  = 774078;
    m2[11] = 409849;
    m2[13] = 207207;
    m2[14] = 101787;
    m2[16] = 49163;
    m2[19] = 23448;
    m2[21] = 11068;
    m2[22] = 5210;
    m2[25] = 2406;
    m2[26] = 1124;
    m2[28] = 510;
    m2[31] = 233;
    m2[32] = 102;
    m2[35] = 45;
    m2[37] = 21;
    m2[38] = 7;
    m2[41] = 3;
    m2[42] = 1;
    cout << cal(m2, 1e12) << endl;
    return 0;
}
