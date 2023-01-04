#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <vector>
const long long e2 = 100;
const long long e4 = e2 * e2;
const long long e8 = e4 * e4;
const long long e7 = e8 / 10;
const long long e9 = e8 * 10;
long long _mod     = e9 + 7;
long long inv_2    = 500000004;
using namespace std; /*}}}*/
long long sg[e7 + 10];
void init_sg() {
    sg[1] = 1;
    for (int i = 3; i < e7; i += 2) {
        sg[i] = Prime::prime_index[Prime::MinPrime(i)];
    }
}

vector<long long> cut(int upper) {
    vector<long long> ret(1048576, 0);
    for (int i = 1; i <= upper; i++)
        ret[sg[i]]++;
    return ret;
}

void FWT_xor(vector<long long> &f, int type) {
    for (int mid = 1; mid < f.size(); mid <<= 1)
        for (int block = mid << 1, j = 0; j < f.size(); j += block)
            for (int i = j; i < j + mid; i++) {
                long long x = f[i], y = f[i + mid];
                f[i]       = (x + y) % _mod * (type == 1 ? 1 : inv_2) % _mod;
                f[i + mid] = (x - y + _mod) % _mod * (type == 1 ? 1 : inv_2) % _mod;
            }
}

vector<long long> mul(vector<long long> a, vector<long long> b) {
    vector<long long> ret(1048576, 0);
    FWT_xor(a, 1);
    FWT_xor(b, 1);
    for (int i = 0; i < 1048576; i++)
        ret[i] = a[i] * b[i] % _mod;
    FWT_xor(ret, -1);
    return ret;
}

long long L(int upper, int cnt) {
    vector<long long> base = cut(upper - 1);
    vector<long long> now(1048576, 0);
    now[0] = 1;

    while (cnt) {
        if (cnt & 1)
            now = mul(now, base);
        base = mul(base, base);
        cnt >>= 1;
    }
    return now[0];
}

int main() {
    Prime::init(e7 + 10);
    init_sg();
    cout << L(5, 2) << endl;
    cout << L(10, 5) << endl;
    cout << L(10, 10) << endl;
    cout << L(1000, 1000) << endl;
    cout << L(e7, e7) << endl;
    return 0;
}
