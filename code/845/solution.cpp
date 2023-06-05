#include "../template/prime.cpp"
#include <iostream>  /*{{{*/
using namespace std; /*}}}*/
long long cache[100][300];

void init() {
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i <= 9; i++)
        cache[1][i] = 1;
    for (int i = 2; i < 100; i++) {
        for (int j = 0; j < 300; j++) {
            for (int k = 0; k <= 9 && j + k < 300; k++) {
                cache[i][j + k] += cache[i - 1][j];
            }
        }
    }
}

long long cal2(int length, int sum) {
    // 长度为length, 之前求和为sum的方案数
    if (length == 0)
        return Prime::is_prime(sum) ? 1 : 0;
    long long ret = 0;
    for (auto i : Prime::prime) {
        if (i < sum)
            continue;
        if (i - sum > length * 9)
            break;
        ret += cache[length][i - sum];
    }
    return ret;
}

long long cal(long long a, long long sum = 0) {
    // 比a小，各位求和为素数的方案数
    long long ans = 0;

    string x = to_string(a);
    int now  = x[0] - '0';

    for (int i = 0; i < now; i++) {
        ans += cal2(x.length() - 1, sum + i);
    }

    if (x.length() == 1)
        ans += Prime::is_prime(sum + a) ? 1 : 0;
    else
        ans += cal(stoll(x.substr(1)), sum + now);

    return ans;
}

long long D(long long query) {
    long long l = 1, r = 1e18;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (cal(mid) >= query) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int main() {
    init();
    Prime::init(500);
    cout << D(61) << endl;
    cout << D(1e8) << endl;
    cout << D(1e16) << endl;
    return 0;
}
