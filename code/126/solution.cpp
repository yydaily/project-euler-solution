#include "../template/bigint.cpp"
#include "../template/china_reminder.cpp"
#include "../template/euler.cpp"
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
long long _mod     = e9 + 7;
using namespace std; /*}}}*/

int gen(int a, int b, int c, int layer) { return 2 * a * c + 2 * b * c + 2 * a * b + 4 * (layer - 1) * (a + b + c + layer - 2); }
const int upper = 20000;
int cnt[upper];
int main() {
    for (int i = 1; gen(i, i + 1, i + 2, 1) < upper; i++) {
        for (int j = i; gen(i, j, j + 1, 1) < upper; j++) {
            for (int k = j; gen(i, j, k, 1) < upper; k++) {
                for (int layer = 1; gen(i, j, k, layer) < upper; layer++) {
                    cnt[gen(i, j, k, layer)]++;
                }
            }
        }
    }
    for (int i = 1; i < upper; i++) {
        if (cnt[i] == 1000) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
