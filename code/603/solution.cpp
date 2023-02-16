#include "../template/prime.cpp"
#include <iostream>/*{{{*/
#include <vector>
long long mod = 1e9 + 7;
using namespace std; /*}}}*/
long long qpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
const long long inv2  = qpow(2, mod - 2);
const long long inv9  = qpow(9, mod - 2);
const long long inv10 = qpow(10, mod - 2);
vector<long long> val;
long long length;
long long power[3]; //  10^{length}  10^{length*k}
long long inv[3];   //  1/(10^{length}-1)    1/(10^{a-1})
long long part1, part2_pre_cal, part4_pre_cal;
long long part2_1, part2_2;
void init(int prime_cnt, long long k) {
    val.push_back(0);
    for (int i = 0; i < prime_cnt; i++) {
        vector<long long> buf;
        while (Prime::prime[i]) {
            buf.push_back(Prime::prime[i] % 10);
            Prime::prime[i] /= 10;
        }
        for (int i = buf.size() - 1; i >= 0; i--) {
            val.push_back(buf[i]);
        }
    }
    length   = val.size() - 1;
    power[0] = qpow(10, length);
    power[1] = qpow(power[0], k);
    inv[0]   = qpow((power[0] + mod - 1) % mod, mod - 2);
    inv[1]   = 10;

    part1         = length * (mod - k % mod * ((k - 1) % mod) % mod * inv2 % mod) % mod;
    part2_1       = power[0] * (power[1] - power[0] + mod) % mod * inv[0] % mod;
    part2_2       = (1 - k % mod + mod) * power[0] % mod;
    part2_pre_cal = (part2_1 + part2_2) * inv[0] % mod * length % mod;
    part4_pre_cal = power[0] * (power[1] - 1) % mod * inv[0] % mod;
}
long long cal(long long a, long long k) {
    long long ret = 0;

    inv[1] = inv[1] * inv10 % mod;

    long long part2 = part2_pre_cal * inv[1] % mod;
    long long part3 = (mod - a) * (k % mod) % mod;
    long long part4 = part4_pre_cal * a % mod * inv[1] % mod;
    ret             = (part1 + part2 + part3 + part4) % mod;

    return ret * val[a] % mod;
}
long long SC(long long n, long long k) {
    init(n, k);
    long long ans = 0;
    for (int i = 1; i <= length; i++) {
        ans += cal(i, k);
        if (ans > mod)
            ans -= mod;
    }
    return ans * inv9 % mod;
}
int main() {
    Prime::init(2e7);
    cout << SC(1e6, 1e12) << endl;
    return 0;
}

/*
$$
ans = \sum_{a=1}^{length} val[a] \sum_{i=0}^{k-1} (a+i*length) * \sum_{j=0}^{(k-i)*length-a+1} 10^j\\
=\sum_{a=1}^{length} val[a] \sum_{i=0}^{k-1} (a+i*length) * \cfrac{10^{(k-i)*length-a+1}-1}{9}
$$
### part 1
$$
\sum_{a=1}^{length} val[a] \sum_{i=0}^{k-1} i*length * \cfrac{10^{(k-i)*length-a+1}-1}{9}\\
=\sum_{a=1}^{length} val[a] *length * inv(9) *\sum_{i=0}^{k-1} i * 10^{(k-i)*length-a+1}-i\\
=\sum_{a=1}^{length} val[a] *length * inv(9) *\left(\left(\sum_{i=0}^{k-1} i * 10^{(k-i)*length-a+1}\right)-\cfrac{k*(k-1)}{2}\right)\\
=\sum_{a=1}^{length} val[a] *length * inv(9) *\left(\left(\sum_{i=0}^{k-1} i * 10^{(k-i)*length}\right) * 10^{1-a}-\cfrac{k*(k-1)}{2}\right)
$$

### part 1.2
$$
\text{sum}(k) = \sum_{i=0}^{k-1} i * 10^{(k-i)*length}\\
10^{length} * \text{sum}(k) = \sum_{i=0}^{k-1} i * 10^{(k-i+1)*length}\\
(10^{length}-1) * \text{sum}(k) \\= 1 * 10^{k*length} + 2*10^{(k-1)*length} + ... (k-1)*10^{2*length} - 1*10^{(k-1)*length} - 2*10^{(k-2)*length} - ... - (k-1) * 10^{length}\\
= 10^{k*length} + 10^{(k-1)*length} + ... + 10^{2*length} - (k-1)*10^{length}\\
=\cfrac{10^{2*length} * (10^{length*(k-1)}-1)}{10^{length}-1} - (k-1) * 10^{length}\\ \space\\\space\\
sum(k) = \cfrac{\cfrac{10^{2*length} * (10^{length*(k-1)}-1)}{10^{length}-1} - (k-1) * 10^{length}}{(10^{length}-1) }
$$
### part 2
$$
\sum_{a=1}^{length} val[a]*a \sum_{i=0}^{k-1} \cfrac{10^{(k-i)*length-a+1}-1}{9}\\
=\sum_{a=1}^{length}val[a]*a*inv(9) * \sum_{i=0}^{k-1} 10^{(k-i)*length-a+1} - 1\\
=\sum_{a=1}^{length}val[a]*a*inv(9) * \left(\left(\sum_{i=0}^{k-1} 10^{(k-i)*length}\right)*10^{1-a} - k\right)\\
=\sum_{a=1}^{length}val[a]*a*inv(9) * \left(\left(\sum_{i=1}^{k} 10^{i*length}\right)*10^{1-a} - k\right)
$$

$$
\sum_{i=1}^{k} 10^{i*length} \\
=\cfrac{10^{length} * (10^{length*k}-1)}{10^{length}-1}
$$

$$
\sum_{a=1}^{length} val[a] * \cfrac{1}{9} * \left(length * \left(\left( \cfrac{\cfrac{10^{2*length} * (10^{length*(k-1)}-1)}{10^{length}-1} - (k-1) * 10^{length}}{(10^{length}-1)
*10^{a-1}}\right)-\cfrac{k*(k-1)}{2}\right) + a * \left(\left(\cfrac{10^{length} * (10^{length*k}-1)}{(10^{length}-1)*10^{a-1}}\right) - k\right)\right) = \\
\sum_{a=1}^{length} val[a] * \cfrac{1}{9} * \left(length * \left(-\cfrac{k*(k-1)}{2}\right) + length * \left( \cfrac{\cfrac{10^{2*length} * (10^{length*(k-1)}-1)}{10^{length}-1} - (k-1) *
10^{length}}{(10^{length}-1) *10^{a-1}}\right) -a*k +  a * \left(\cfrac{10^{length} * (10^{length*k}-1)}{(10^{length}-1)*10^{a-1}}\right)\right)\\
=\sum_{a=1}^{length} val[a] * \cfrac{1}{9} * \left(length * \left(-\cfrac{k*(k-1)}{2}\right) + length * \left( \cfrac{\cfrac{10^{length} * (10^{length*k}-10^{length})}{10^{length}-1} - (k-1) *
10^{length}}{(10^{length}-1) *10^{a-1}}\right) -a*k +  a * \left(\cfrac{10^{length} * (10^{length*k}-1)}{(10^{length}-1)*10^{a-1}}\right)\right)
$$
*/
