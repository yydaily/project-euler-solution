#include "../template/prime.cpp"
#include "../template/progress_rate.cpp"
#include <iostream>
const long long mod = 1001961001;
using namespace std;

//=====force solution========/
long long pow(long long a, long long power) {
    long long ret = 1;
    while (power) {
        if (power & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        power >>= 1;
    }
    return ret;
}

map<long long, long long> generate(long long p, int cnt) {
    map<long long, long long> m;
    if (p == 2 && cnt == 1) {
        m[8] = 2;
        return m;
    }
    if (p == 2 && cnt == 2) {
        m[32] = 1;
        m[64] = 2;
        m[96] = 1;
        return m;
    }
    if (p == 2) {
        auto now = generate(p, cnt - 1);
        for (auto i : now) {
            if (i.second == 1 && i.first == pow(p, cnt * 2 - 2) * 2 % mod) {
                m[i.first * 4 % mod]  = 1;
                m[i.first * 12 % mod] = 1;
            } else {
                m[i.first * 8 % mod] = i.second * 2;
            }
        }
        return m;
    }

    if (cnt == 1) {
        m[(pow(p, 3) - p + mod) % mod]     = p - 1;
        m[(pow(p, 3) + p * (p - 1)) % mod] = 1;
        return m;
    }

    auto now = generate(p, cnt - 1);
    for (auto i : now) {
        if (i.second == 1) {
            m[(i.first * pow(p, 3) % mod - pow(p, 2 * cnt - 1) + mod) % mod]           = p - 1;
            m[(i.first * pow(p, 3) % mod + (p - 1) * pow(p, 2 * cnt - 1) % mod) % mod] = 1;
        } else {
            m[i.first * pow(p, 3) % mod] = i.second * p % mod;
        }
    }
    return m;
}

map<long long, long long> merge(map<long long, long long> &a, map<long long, long long> b) {
    map<long long, long long> ret;
    for (auto i : a) {
        for (auto j : b) {
            ret[(i.first * j.first) % mod] += i.second * j.second % mod;
        }
    }
    return ret;
}

long long q(long long a) {
    map<long long, long long> m;
    m[1] = 1;
    while (a != 1) {
        long long p = Prime::MinPrime(a);
        int cnt     = 1;
        a /= p;
        while (a % p == 0) {
            cnt++;
            a /= p;
        }
        m = merge(m, generate(p, cnt));
    }
    long long ans = 0;
    for (auto i : m) {
        ans = (ans + i.first * i.first % mod * i.second % mod) % mod;
    }
    return ans;
}

// =======optimized solution=========/
const long long inv7 = 143137286;
long long cal(long long p, long long power) {
    if (p == 2)
        return (pow(2, 3 * power) - 1 + mod) % mod * pow(2, 4 * power + 3) % mod * inv7 % mod;
    return (pow(p, 7 * power) + (pow(p, 7 * power) - pow(p, 4 * power) + mod) % mod * (pow(p * ((p * p % mod + p + 1 + mod) % mod) % mod, mod - 2)) % mod) % mod;
}
long long q2(long long a) {
    long long ans = 1;
    while (a != 1) {
        long long p = Prime::MinPrime(a);
        int cnt     = 1;
        a /= p;
        while (a % p == 0) {
            cnt++;
            a /= p;
        }
        ans = (ans * cal(p, cnt)) % mod;
    }
    return ans;
}

long long Q(long long a) {
    Prime::init(a + 1);
    long long ans = 0;
    ProgressBar::init();
    for (long long i = 1; i <= a; i++) {
        ProgressBar::print_bar(i, a);
        // ans = (ans+q(i)) % mod;
        ans = (ans + q2(i)) % mod;
    }
    return ans;
}

int main() {
    // cout<<Q(10)<<endl;
    cout << Q(12345678) << endl;
    return 0;
}
