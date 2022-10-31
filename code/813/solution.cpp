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
long long mod      = e9 + 7;
using namespace std; /*}}}*/
vector<__int128> mul(vector<__int128> &a, vector<__int128> &b) {
    map<__int128, int> m;
    for (auto i : a)
        for (auto j : b) {
            m[i + j]++;
        }
    vector<__int128> ret;
    int ind = 0;
    for (auto i : m) {
        if (i.second & 1)
            ret.push_back(i.first);
    }
    ////show(ret); cout<<endl;
    return ret;
}
vector<__int128> resolve(__int128 n, vector<__int128> base) {
    vector<__int128> ret;
    ret.push_back(0);
    while (n) {
        if (n & 1)
            ret = mul(ret, base);
        base = mul(base, base);
        n >>= 1;
    }
    return ret;
}
long long qpow2(__int128 a) {
    long long ret  = 1;
    long long base = 2;
    while (a) {
        if (a & 1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        a >>= 1;
    }
    return ret;
}
long long value(vector<__int128> l) {
    long long ret = 0;
    for (auto i : l) {
        ret = (ret + qpow2(i)) % mod;
    }
    return ret;
}
int main() {
    long long n = 1;
    for (int i = 0; i < 12; i++)
        n *= 8;
    vector<__int128> base(3);
    base[0] = 0, base[1] = 1, base[2] = 3;
    base = resolve(n, base);

    n = 1;
    for (int i = 0; i < 8; i++)
        n *= 12;
    base = resolve(n, base);

    cout << value(base) << endl;
    return 0;
}
