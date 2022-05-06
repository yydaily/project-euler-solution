#include <iostream>
#include <vector>
using namespace std;
const long long upper = 5e15;
vector<long long> v;
int main() {
    // 2n^2 + 2n + 1;
    v.push_back(0);
    for (long long n = 1; n < 5e7; n++) {
        long long now = 2 * n * n + 2 * n + 1;
        v.push_back(now);
    }

    int ans = 0;
    for (long long i = 1; i < v.size(); i++) {
        long long p = v[i];
        if (p == 2 * i * i + 2 * i + 1)
            ans++;
        if (p <= 1)
            continue;
        for (long long j = i; j < v.size(); j += p) {
            while (v[j] % p == 0)
                v[j] /= p;
        }
        for (long long j = p - 1 - i; j < v.size(); j += p) {
            while (v[j] % p == 0)
                v[j] /= p;
        }
    }
    cout << ans << endl;
    return 0;
}
