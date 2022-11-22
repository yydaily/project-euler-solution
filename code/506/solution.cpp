#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
#include "../template/fibonacci.cpp"
#include "../template/pell.cpp"
#include "../template/prime.cpp"
#include "../template/prime_cnt.cpp"
#include <cstdlib>
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
long long _mod     = e9 + 7;
using namespace std; /*}}}*/
long long ans[833326];
int main() {
    long long data[] = {1, 2, 3, 4, 3, 2};
    long long mod    = 123454321;
    long long sum    = 0;

    int index = 0;
    for (int i = 1; i <= 833325; i++) {
        ans[i]        = 0;
        long long now = i;
        while (now > 0) {
            if (index == 0 && now >= 15) {
                now -= 15;
                ans[i] = (ans[i] * 1000000 + 123432) % mod;
                continue;
            }
            ans[i] = (ans[i] * 10 + data[index]) % mod;
            now -= data[index];
            index++;
            if (index == 6) {
                index = 0;
            }
        }

        sum = (sum + ans[i]) % mod;
    }

    long long need = 1e14;
    long long rans = ((need / 833325) % mod * sum) % mod;
    need %= 833325;
    for (int i = 1; i <= need; i++) {
        rans = (rans + ans[i]) % mod;
    }
    cout << rans << endl;
    return 0;
}
