#include <iostream>/*{{{*/
#include <map>
#include <math.h>
#include <vector>
using namespace std; /*}}}*/
long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
map<long long, vector<long long>> m;
inline void cal(long long i, long long j, long long upper) {
    long long base1 = j * j - i * i;
    long long base2 = 2 * i * j;
    for (long long k = upper / 2 / max(base1, base2); k >= 1; k--) {
        m[k * base1].push_back(base2 * k);
        m[k * base2].push_back(base1 * k);
    }
}

long long cal(long long a_2, long long hight, long long hight_and_b, long long upper) {
    if (hight_and_b <= hight * 2)
        return 0;
    long long c = sqrt(hight * hight + a_2 * a_2);
    a_2 *= 2;
    hight_and_b -= hight;
    long long x = a_2 * a_2 + hight_and_b * hight_and_b;
    long long y = sqrt(x);
    if (y * y == x && a_2 + hight_and_b * 2 + c * 2 <= upper) {
        // cout<<a_2<<' '<<hight_and_b<<' '<<c<<' '<< a_2 + hight_and_b * 2 + c * 2<<endl;
        return a_2 + hight_and_b * 2 + c * 2;
    }
    return 0;
}

long long solve(long long upper) {
    m.clear();
    for (long long i = 1; i <= upper; i++) {
        long long j_upper = min(upper / 4.0 / i, sqrt(upper / 2 - i * i));
        for (long long j = i + 1; j <= j_upper; j += 2) {
            if (gcd(i, j) == 1) {
                cal(i, j, upper);
            }
        }
    }

    long long ans = 0;
    for (auto a_2 : m) {
        if (a_2.second.size() <= 1)
            continue;
        sort(a_2.second.begin(), a_2.second.end());
        for (int i = 0; i < a_2.second.size(); i++) {
            for (int j = i + 1; j < a_2.second.size(); j++) {
                ans += cal(a_2.first, a_2.second[i], a_2.second[j], upper);
            }
        }
    }
    return ans;
}
int main() {
    cout << solve(1e4) << endl;
    cout << solve(1e7) << endl;
    return 0;
}
