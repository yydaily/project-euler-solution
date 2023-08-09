#include "../template/prime.cpp"
#include <iostream>/*{{{*/
long long mod = 999676999;
const int e5  = 1e5;
using namespace std; /*}}}*/
long long D[e5];
long long sum_D[e5];
void init_d() {
    Prime::init(e5);
    sum_D[0] = 0;
    sum_D[1] = 1;
    D[1]     = 1;
    for (int i = 2; i < e5; i++) {
        if (Prime::is_prime(i))
            D[i] = 1;
        else {
            int p = Prime::MinPrime(i);
            D[i]  = (D[p] * (i / p) + D[i / p] * p) % mod;
        }
        sum_D[i] = sum_D[i - 1] + D[i];
        if (sum_D[i] > mod)
            sum_D[i] -= mod;
    }
}

long long cache[50000 + 1][50000 + 1];

int main() {
    init_d();
    for (int i = 1; i <= 50000; i++) {
        cache[i][i] = D[i];
        for (int j = i - 1; j >= 1; j--) {
            cache[i][j] = (cache[i][j + 1] + D[j]) % mod;
            if (j * 2 <= i)
                cache[i][j] = (cache[i][j] + D[j] * cache[i - j][j]) % mod;
        }
    }
    cout << cache[10][1] << endl;
    cout << cache[50000][1] << endl;
    return 0;
}
