#include <iostream>/*{{{*/
#include <map>
#include <vector>
using namespace std; /*}}}*/

map<long long, int> get_all_primes(long long a) { /*{{{*/
    map<long long, int> ret;
    for (long long i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            ret[i]++;
            a /= i;
        }
    }
    if (a != 1)
        ret[a] = 1;
    return ret;
} /*}}}*/
vector<long long> get_all_factor(long long a) { /*{{{*/
    auto p = get_all_primes(a);
    vector<long long> ret;
    ret.push_back(1);
    for (auto i : p) {
        int s         = ret.size();
        long long now = 1;
        for (int cnt = 1; cnt <= i.second; cnt++) {
            now *= i.first;
            for (int x = 0; x < s; x++)
                ret.push_back(ret[x] * now);
        }
    }
    return ret;
} /*}}}*/
long long gcd(long long a, long long b) { /*{{{*/
    if (a == 0)
        return b;
    return gcd(b % a, a);
} /*}}}*/
void gen(long long &a, long long &b) {
    while (gcd(a + 1, b) != 1) {
        a++;
        b += gcd(a, b);
    }
    long long x = b * 100;
    for (auto fac : get_all_factor(b - a - 1)) {
        if (fac == 1)
            continue;
        x = min(x, fac - (a + 1) % fac);
    }
    a += x + 1;
    b += x + gcd(a, b + x);
}
int main() {
    long long index = 4, val = 13;
    long long ans   = 0;
    long long upper = 1e15;
    while (true) {
        cout << index << ' ' << val << endl;
        ans = upper - index + val;
        gen(index, val);
        if (index > upper)
            break;
    }
    cout << ans << endl;
    return 0;
}
